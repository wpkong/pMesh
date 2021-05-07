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
    public:
        using VertexType = Vertex<VertexND, CellND, HalfEdgeTrait, VertexTrait, CellTrait>;
        using CellType = Cell<VertexND, CellND, HalfEdgeTrait, VertexTrait, CellTrait>;
        using EdgeType = Edge<VertexND, CellND, HalfEdgeTrait, VertexTrait, CellTrait>;
        using HalfEdgeType = HalfEdge<VertexND, CellND, HalfEdgeTrait, VertexTrait, CellTrait>;
        using MeshType = Mesh<VertexND, CellND, HalfEdgeTrait, VertexTrait, CellTrait>;

    public:
        using halfedge_wptr = std::weak_ptr<HalfEdgeType>;
        using cell_wptr = std::weak_ptr<CellType>;
    public:
        size_t vertex_start;
        size_t vertex_end;
    public:
        halfedge_wptr opposite;
        halfedge_wptr next;
        halfedge_wptr prev;
    public:
        cell_wptr cell;

    public:
        HalfEdgeTrait trait;
    };
}

#endif //PMESH_HALFEDGE_H
