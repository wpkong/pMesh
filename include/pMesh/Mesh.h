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

    public:
        /**
         * Calculate vertices_kring and cells_kring
         */
        void inflate_krings();

    public:
        /**
         * Get v-pair via cell-pair
         * @param cell_a
         * @param cell_b
         * @return
         */
        Edge get_edge(size_t cell_a, size_t cell_b);
    };
};

#include <pMesh/Mesh.impl>

#endif //PMESH_MESH_H
