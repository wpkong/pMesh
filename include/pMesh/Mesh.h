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
    template<int VertexND, int CellND>
    class Mesh {
    public:
        std::vector<PointNd<VertexND>> vertices;
        std::vector<Cell<CellND>> cells;

        std::vector<std::set<size_t>> vertices_kring;
        std::vector<std::set<size_t>> cells_kring;
    };
};

#endif //PMESH_MESH_H
