/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/3/27
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef RBF_KERNELS_H
#define RBF_KERNELS_H

#include <functional>

namespace RBF {
    namespace kernel {
        class kernel_function {
        public:
            virtual double operator()(double v) const = 0;
        };

        class gaussian_kernel : public kernel_function {
        private:
            double sigma;
        public:
            explicit gaussian_kernel(double sigma);

            double operator()(double v) const override;
        };

        class multiquadric_kernel : public kernel_function {
        private:
            double sigma;
        public:
            explicit multiquadric_kernel(double sigma);

            double operator()(double v) const override;
        };

        class linear_kernel : public kernel_function {
            double operator()(double v) const override;
        };

        class cubic_kernel : public kernel_function {
            double operator()(double v) const override;
        };

        class thinplate_kernel : public kernel_function {
            double operator()(double v) const override;
        };

        class lambda_kernel : public kernel_function {
        private:
            std::function<double(double v)> &lambda;
        public:
            explicit lambda_kernel(std::function<double(double)> &lambda);

            double operator()(double v) const override;
        };
    };
};

#endif //RBF_KERNELS_H
