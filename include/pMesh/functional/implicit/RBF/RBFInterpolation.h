/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/3/27
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef RBF_RBFINTERPOLATION_H
#define RBF_RBFINTERPOLATION_H

#include "definitions.h"
#include "kernels.h"
#include "LinearSolverType.h"

namespace RBF {
    class RBFInterpolation {
    private:
        std::shared_ptr<kernel::kernel_function> kf = nullptr;
        Eigen::MatrixXd control_values;
        Eigen::MatrixXd weights;

    public:
        /**
         *
         * @param points  n * d  // n: sample size, d dimension
         * @param kernel
         */
        explicit RBFInterpolation(Eigen::MatrixXd x,
                                  Eigen::VectorXd y,
                                  const std::shared_ptr<kernel::kernel_function> kernel,
                                  double sigma = 0,
                                  const LinearSolver::Solver &linear_solver = LinearSolver::LDLTSolver(true));

        RBFInterpolation(const RBFInterpolation &obj);

        RBFInterpolation() = default;

        Eigen::MatrixXd eval(const Eigen::MatrixXd &x);
    };
}

#endif //RBF_RBFINTERPOLATION_H
