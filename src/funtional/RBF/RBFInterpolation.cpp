/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/3/27
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#include <pMesh/functional/RBF/RBFInterpolation.h>

#include <map>
#include <Eigen/IterativeLinearSolvers>
#include <boost/log/trivial.hpp>
#include <boost/timer.hpp>

pMesh::RBF::RBFInterpolation::RBFInterpolation(const RBFInterpolation &obj) :
        kf(obj.kf) {
    this->control_values = obj.control_values;
    this->weights = obj.weights;
}

pMesh::RBF::RBFInterpolation::RBFInterpolation(Eigen::MatrixXd x,
                                        Eigen::VectorXd y,
                                        const std::shared_ptr<kernel::kernel_function> kf,
                                        double sigma,
                                        const LinearSolver::Solver &linear_solver) : kf(kf) {
    this->control_values = x;
    int n = x.rows();
    int d = x.cols();
    assert(n == y.rows());
    Eigen::MatrixXd A, w, b;
    Eigen::MatrixXd Phi, P, lambda, gama;

    if (linear_solver.verbose) {
        BOOST_LOG_TRIVIAL(info) << "Assembling A and b";
    }
    // init Phi
    {
        Phi = Eigen::MatrixXd::Zero(n, n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                double v = (*kf)((x.row(i) - x.row(j)).norm());
                Phi(i, j) = v;
                Phi(j, i) = v;
            }
        }
    }

    // init P
    {
        P = Eigen::MatrixXd::Zero(n, d + 1);
        P.leftCols(1) = Eigen::MatrixXd::Ones(n, 1);
        P.rightCols(x.cols()) = x;
    }

    // assemble A
    {
        A = Eigen::MatrixXd::Zero(n + d + 1, n + d + 1);
        A.topLeftCorner(n, n) = Phi;
        A.topRightCorner(P.rows(), P.cols()) = P;
        A.bottomLeftCorner(P.cols(), P.rows()) = P.transpose();

        A += Eigen::MatrixXd::Identity(n + d + 1, n + d + 1) * std::pow(sigma, 2);
    }

    // assemble b
    {
        b = Eigen::MatrixXd::Zero(n + d + 1, 1);
        b.topRows(n) = y;
    }

    if (linear_solver.verbose) {
        BOOST_LOG_TRIVIAL(info) << "Assembled Phi with shape of [" << Phi.rows() << " x " << Phi.cols() << " ]";
        BOOST_LOG_TRIVIAL(info) << "Assembled P with shape of [" << P.rows() << " x " << P.cols() << " ]";
        BOOST_LOG_TRIVIAL(info) << "Assembled A with shape of [" << A.rows() << " x " << A.cols() << " ]";
        BOOST_LOG_TRIVIAL(info) << "Assembled b with shape of [" << b.rows() << " x " << b.cols() << " ]";
    }

    if (linear_solver.verbose) {
        BOOST_LOG_TRIVIAL(info) << "Start solving Ax=b";
    }
    // solve
    boost::timer tiktok;
    switch (linear_solver.solver_type) {
        case LinearSolver::SolverType::PartialPivLu:
            this->weights = A.partialPivLu().solve(b);
        case LinearSolver::SolverType::FullPivLu:
            this->weights = A.fullPivLu().solve(b);
            break;
        case LinearSolver::SolverType::HouseholderQr:
            this->weights = A.householderQr().solve(b);
            break;
        case LinearSolver::SolverType::ColPivHouseholderQr:
            this->weights = A.colPivHouseholderQr().solve(b);
            break;
        case LinearSolver::SolverType::FullPivHouseholderQr:
            this->weights = A.fullPivHouseholderQr().solve(b);
            break;
        case LinearSolver::SolverType::LLT:
            this->weights = A.llt().solve(b);
            break;
        case LinearSolver::SolverType::LDLT:
            this->weights = A.ldlt().solve(b);
            break;
        case LinearSolver::SolverType::ConjugateGradient: {
            auto cgs = (LinearSolver::ConjugateGradientSolver *) &linear_solver;
            Eigen::ConjugateGradient<Eigen::MatrixXd, Eigen::Lower | Eigen::Upper, Eigen::IdentityPreconditioner> cg(A);
            if (linear_solver.verbose) {
                BOOST_LOG_TRIVIAL(info) << "********* ConjugateGradient Info: *********";
                BOOST_LOG_TRIVIAL(info) << "max iterations: " << cgs->max_iterations;
                BOOST_LOG_TRIVIAL(info) << "tolerance:      " << cgs->tolerance;
                BOOST_LOG_TRIVIAL(info) << "*********************************************";
            }
            cg.setMaxIterations(cgs->max_iterations);
            cg.setTolerance(cgs->tolerance);
            this->weights = cg.solve(b);

            if (linear_solver.verbose) {
                BOOST_LOG_TRIVIAL(info) << "********* ConjugateGradient Digest: *********";
                BOOST_LOG_TRIVIAL(info) << "iterations: " << cg.iterations();
                BOOST_LOG_TRIVIAL(info) << "error:      " << cg.error();
                BOOST_LOG_TRIVIAL(info) << "return:     " << cg.info();
                BOOST_LOG_TRIVIAL(info) << "*********************************************";
            }
        }
            break;
        default:
            throw std::range_error("No Such Linear Solver.");
    }

    if (linear_solver.verbose) {
        BOOST_LOG_TRIVIAL(info) << "Solver takes " << tiktok.elapsed() << "s";
    }
}

Eigen::MatrixXd pMesh::RBF::RBFInterpolation::eval(const Eigen::MatrixXd &x) {
    if (kf == nullptr) {
        throw std::runtime_error("kernel function can not be null");
    }
    int cv_n = this->control_values.rows();
    int n = x.rows();
    int d = x.cols();
    Eigen::MatrixXd A, w, b;
    Eigen::MatrixXd Phi, P;

    // init Phi
    {
        Phi = Eigen::MatrixXd::Zero(n, cv_n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < cv_n; ++j) {
                double v = (*kf)((x.row(i) - control_values.row(j)).norm());
                Phi(i, j) = v;
            }
        }
    }

    // init P
    {
        P = Eigen::MatrixXd::Zero(n, d + 1);
        P.leftCols(1) = Eigen::MatrixXd::Ones(n, 1);
        P.rightCols(x.cols()) = x;
    }

    // assemble A
    {
        A = Eigen::MatrixXd::Zero(n, cv_n + d + 1);
        A.topLeftCorner(n, cv_n) = Phi;
        A.topRightCorner(P.rows(), P.cols()) = P;
    }

    return A * weights;
}
