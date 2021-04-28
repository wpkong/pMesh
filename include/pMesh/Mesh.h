/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/4/28
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_MESH_H
#define PMESH_MESH_H

#include <pMesh/Common.h>
#include <vector>
#include <array>

namespace pMesh {
    template<int T>
    using Cell = std::array<size_t, T>;

    template<int NC>
    class Mesh {
    public:
        std::vector<Point3d> vertices;
        std::vector<Cell<NC>> cells;
    };
};

#endif //PMESH_MESH_H
