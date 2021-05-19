/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/3/27
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef RBF_DEFINITIONS_H
#define RBF_DEFINITIONS_H

#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Core>
#include <vector>

namespace pMesh::RBF {
    typedef Eigen::Matrix<double, 3, 1> Point3d;
    typedef Eigen::Matrix<double, 3, 1> Vector3d;

    template<int N>
    typename Eigen::Matrix<double, N, 1> PointNd;

    using std::vector;
    using std::pair;
};

#endif //RBF_DEFINITIONS_H
