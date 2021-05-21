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
#include <pMesh/meshes/TriangleMesh.h>
#include <boost/tuple/tuple.hpp>
#include <functional>

namespace pMesh {
    using signed_directional_field = std::function<double(Point3d)>;
    using grad_func = std::function<Vector3d(Point3d)>;
    using Range = std::pair<double, double>;
    using Domain3d = boost::tuple<Range, Range, Range>;
    using Size3d = boost::tuple<double, double, double>;

    class Cube {

    };

    Triangle3dMesh<> isosurface(signed_directional_field &sdf, const Domain3d &domain, const Size3d &size);
}


#endif //PMESH_MARCHINGCUBES_H
