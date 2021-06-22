/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/6/22
 * @email: yjxkwp@foxmail.com
 * @site: https://donot.fit
 * @description: 
 * ------------------------------------
**/


#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#include <pMesh/functional/RBF/RBFInterpolation.h>
#include <boost/test/unit_test.hpp>
#include <boost/log/trivial.hpp>
#include <boost/math/special_functions/sin_pi.hpp>
#include <boost/math/special_functions/cos_pi.hpp>


BOOST_AUTO_TEST_SUITE(test)
    BOOST_AUTO_TEST_CASE(test_3d) {
        using namespace pMesh::RBF;
        int density = 10;
        double eps = 0.1;
        double sig = 0.05;
        Eigen::Matrix<double, -1, 3> x;
        Eigen::Matrix<double, -1, 1> y;
        Eigen::Matrix<double, -1, 3> z;
        int sample_n = (2 * density) * (density-1);
        x.resize(2 * sample_n, 3);
        y = Eigen::MatrixXd::Zero(2 * sample_n, 1);

        int cnt = 0;
        for (int i = 0; i < 2 * density; ++i) {
            for (int j = 1; j < density; ++j) {
                double phi = 1.0 / density * i;
                double theta = 1.0 / density * j;
                double r = 1;
                double x_ = boost::math::sin_pi(theta) * boost::math::cos_pi(phi);
                double y_ = boost::math::sin_pi(theta) * boost::math::sin_pi(phi);
                double z_ = boost::math::cos_pi(theta);

                x.row(cnt) = Eigen::Matrix<double, 1, 3>(r * x_, r * y_, r * z_);
                y(sample_n + cnt, 0) = 0;

                r += sig;
                x.row(sample_n + cnt) = Eigen::Matrix<double, 1, 3>(r * x_, r * y_, r * z_);
                y(sample_n + cnt, 0) = eps;

                cnt++;
            }
        }

        vector<Point3d> data1;
        for (int i = 0; i < x.rows(); ++i) {
            data1.push_back(x.row(i).transpose());
        }

        BOOST_LOG_TRIVIAL(debug) << "Training with: ";
        BOOST_LOG_TRIVIAL(debug) << "x: ";
        std::cout  << x.transpose() << std::endl;
        BOOST_LOG_TRIVIAL(debug) << "y: ";
        std::cout  << y.transpose() << std::endl;

        pMesh::RBFInterpolation interpolation(x, y, std::make_shared<kernel::cubic_kernel>(), 0);

        double test_density = 4;
        Eigen::Matrix<double, -1, 3> test;
        test.resize(3 * 2 *test_density * test_density, 3);

        cnt = 0;
        for (int i = 0; i < 2 * test_density; ++i) {
            for (int j = 0; j < test_density; ++j) {
                double phi = 1.0 / test_density * i;
                double theta = 1.0 / test_density * j;

                double r = 1;
                double x_ = boost::math::sin_pi(theta) * boost::math::cos_pi(phi);
                double y_ = boost::math::sin_pi(theta) * boost::math::sin_pi(phi);
                double z_ = boost::math::cos_pi(theta);

                test.row(cnt) = Eigen::Matrix<double, 1, 3>(r * x_, r * y_, r * z_);
                cnt++;

                r = 0.5;
                test.row(cnt) = Eigen::Matrix<double, 1, 3>(r * x_, r * y_, r * z_);
                cnt++;

                r = 2;
                test.row(cnt) = Eigen::Matrix<double, 1, 3>(r * x_, r * y_, r * z_);
                cnt++;
            }
        }

        vector<Point3d> data2;
        for (int i = 0; i < test.rows(); ++i) {
            data2.push_back(test.row(i).transpose());
        }

        Eigen::MatrixXd v = interpolation.eval(test);
        BOOST_LOG_TRIVIAL(debug) << "Testing with: ";
        BOOST_LOG_TRIVIAL(debug) << "x: ";
        std::cout  << test.transpose() << std::endl;
        BOOST_LOG_TRIVIAL(debug) << "y: ";
        std::cout  << v.transpose() << std::endl;
    }
BOOST_AUTO_TEST_SUITE_END()