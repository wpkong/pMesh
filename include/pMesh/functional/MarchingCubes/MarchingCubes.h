/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/21
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_MARCHINGCUBES_H
#define PMESH_MARCHINGCUBES_H

#include <pMesh/Common.h>
#include <pMesh/mesh/TriangleMesh.h>
#include <boost/tuple/tuple.hpp>
#include <eigen3/unsupported/Eigen/CXX11/Tensor>
#include <functional>

namespace pMesh {
    using signed_directional_field = std::function<double(const Point3d&)>;
    using grad_func = std::function<Vector3d(const Point3d &)>;
    using Range = std::pair<double, double>;
    using Domain3d = boost::tuple<Range, Range, Range>;
    using Size3d = boost::tuple<double, double, double>;
    using Tensor3d = Eigen::Tensor<double,3>;

    struct Cube {
        Point3d vertices[8];
        double f_value[8];

    };

    Triangle3dMesh<> isosurface(
            signed_directional_field sdf, const Domain3d &domain, const Vector3d &size,
            double level = 0, grad_func grad = nullptr, bool compact_points = true);

    Triangle3dMesh<> isosurface(
            const Tensor3d &distance_field,
            double level = 0, bool compact_points = true);
}


#endif //PMESH_MARCHINGCUBES_H
