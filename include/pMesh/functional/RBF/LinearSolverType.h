/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/4/14
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef RBF_LINEARSOLVERTYPE_H
#define RBF_LINEARSOLVERTYPE_H

#define DEFINE_RBF_SOLVER(solver) \
class solver##Solver: public Solver{ \
public:   \
explicit solver##Solver() = delete;   \
explicit solver##Solver(bool verbose): Solver(SolverType::solver, verbose){} \
};

namespace pMesh::RBF {
    namespace LinearSolver {
        enum class SolverType {
            PartialPivLu = 0,
            FullPivLu,
            HouseholderQr,
            ColPivHouseholderQr,
            FullPivHouseholderQr,
            LLT,
            LDLT,
            ConjugateGradient,
        };

        class Solver {
        public:
            explicit Solver() = delete;

        protected:
            explicit Solver(SolverType solver_type, bool verbose) : solver_type(solver_type),
                                                                    verbose(verbose) {}

        public:
            const bool verbose;
            const SolverType solver_type;
        };

        DEFINE_RBF_SOLVER(PartialPivLu);

        DEFINE_RBF_SOLVER(FullPivLu);

        DEFINE_RBF_SOLVER(HouseholderQr);

        DEFINE_RBF_SOLVER(ColPivHouseholderQr);

        DEFINE_RBF_SOLVER(FullPivHouseholderQr);

        DEFINE_RBF_SOLVER(LLT);

        DEFINE_RBF_SOLVER(LDLT);


        class ConjugateGradientSolver : public Solver {
        public:
            const int max_iterations;
            const double tolerance;
        public:
            explicit ConjugateGradientSolver() = delete;
            explicit ConjugateGradientSolver(int max_iterations, double tolerance, bool verbose) :
                    Solver(SolverType::ConjugateGradient, verbose),
                    max_iterations(max_iterations),
                    tolerance(tolerance) {}
        };
    }
};


#endif //RBF_LINEARSOLVERTYPE_H
