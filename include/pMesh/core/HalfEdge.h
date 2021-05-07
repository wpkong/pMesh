/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/7
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_HALFEDGE_H
#define PMESH_HALFEDGE_H

#include <pMesh/Common.h>
#include <pMesh/core/Trait.h>
#include <pMesh/core/Decl.h>

namespace pMesh{
    template<int VertexND,
            int CellND,
            class HalfEdgeTrait,
            class VertexTrait,
            class CellTrait>
    class HalfEdge{
        using halfedge_wptr_self = halfedge_wptr<VertexND, CellND, HalfEdgeTrait, VertexTrait, CellTrait>;
        using cell_wptr_self = cell_wptr<VertexND, CellND, HalfEdgeTrait, VertexTrait, CellTrait>;
    public:
        size_t vertex_start;
        size_t vertex_end;
    public:
        halfedge_wptr_self opposite;
        halfedge_wptr_self next;
        halfedge_wptr_self prev;
    public:
        cell_wptr_self cell;

    public:
        HalfEdgeTrait trait;
    };
}

#endif //PMESH_HALFEDGE_H
