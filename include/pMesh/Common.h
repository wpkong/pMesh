/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/4/28
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_COMMON_H
#define PMESH_COMMON_H

#include <Eigen/Core>
#include <vector>
#include <set>
#include <memory>
#include <array>

namespace pMesh {
    // Points and vectors
    template<int N>
    using VectorNd = Eigen::Matrix<double, N, 1>;

    template<int N>
    using PointNd = VectorNd<N>;

    using Vector3d = VectorNd<3>;
    using Point3d = VectorNd<3>;

    using Vector2d = VectorNd<2>;
    using Point2d = PointNd<2>;


};

#endif //PMESH_COMMON_H
