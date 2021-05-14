/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/7
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_SURFACE_CELL_H
#define PMESH_SURFACE_CELL_H

#include <pMesh/Common.h>
#include <pMesh/core/Surface/Decl.h>
#include <pMesh/core/ExtraData.h>

namespace pMesh {
    class Cell {
    public:
        int id = -1;

    public:
        std::vector<VertexHandle> vertices;

    public:
        std::vector<HalfEdgeHandle> half_edges;
    };
}

#endif //PMESH_SURFACE_CELL_H