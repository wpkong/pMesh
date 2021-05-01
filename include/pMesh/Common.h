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

namespace pMesh {
    // Points and vectors
    template<int N>
    using VectorNd = Eigen::Matrix<double, N, 1>;
    using PointNd = VectorNd;

    using Vector3d = VectorNd<3>;
    using Point3d = VectorNd<3>;

    using Vector2d = VectorNd<2>;
    using Point2d = PointNd<2>;

    // meshes
    template<int T>
    using Cell = std::array<size_t, T>;
    using TriangleCell = Cell<3>;
    using TetrehedronCell = Cell<4>;
    using QuadrangleCell = Cell<4>;
    using HexahedronCell = Cell<8>;

};

#endif //PMESH_COMMON_H
