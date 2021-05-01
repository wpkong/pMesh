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
    template<class T_vertex, class T_cell>
    class Mesh {
    public:
        std::vector<T_vertex> vertices;
        std::vector<T_cell> cells;

        std::vector<std::set<size_t>> vertices_kring;
    public:
        void regulate(bool reverse=false);
    };
};

#endif //PMESH_MESH_H
