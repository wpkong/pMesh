/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/3/27
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#include "RBF/kernels.h"
#include <cmath>

namespace RBF {
    namespace kernel {
        gaussian_kernel::gaussian_kernel(double sigma) : sigma(sigma) {}

        double gaussian_kernel::operator()(double v) const {
            return std::exp(-std::pow(v / sigma, 2));
        }

    }

    namespace kernel {
        multiquadric_kernel::multiquadric_kernel(double sigma) : sigma(sigma) {}

        double multiquadric_kernel::operator()(double v) const {
            return std::sqrt(1 + std::pow(v, 2) / std::pow(sigma, 2));
        }
    }

    namespace kernel {
        double linear_kernel::operator()(double v) const {
            return v;
        }
    }

    namespace kernel {
        double cubic_kernel::operator()(double v) const {
            return std::pow(v, 3);
        }
    }

    namespace kernel {
        double thinplate_kernel::operator()(double v) const {
            return std::pow(v, 2) * std::log(v + 1);
        }
    }

    namespace kernel {
        lambda_kernel::lambda_kernel(std::function<double(double)> &lambda) : lambda(lambda) {}

        double lambda_kernel::operator()(double v) const {
            return this->lambda(v);
        }
    }
};