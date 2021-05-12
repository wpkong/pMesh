/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/7
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_CELL_H
#define PMESH_CELL_H

#include <pMesh/Common.h>
#include <pMesh/core/Decl.h>
#include <pMesh/core/ExtraData.h>

namespace pMesh {
    class Cell {
        int id = -1;

    public:
        std::vector<VertexHandle> vertices;

    public:
        std::vector<HalfEdgeHandle> half_edges;
    };
}

#endif //PMESH_CELL_H
