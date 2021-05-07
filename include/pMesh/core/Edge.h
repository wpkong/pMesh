/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/8
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_EDGE_H
#define PMESH_EDGE_H

#include <pMesh/Common.h>
#include <pMesh/core/Trait.h>
#include <pMesh/core/Decl.h>

namespace pMesh{
    template<int VertexND,
            int CellND,
            class HalfEdgeTrait=NullTrait,
            class VertexTrait=NullTrait,
            class CellTrait=NullTrait>
    class Edge{
    public:
        using VertexType = Vertex<VertexND, CellND, HalfEdgeTrait, VertexTrait, CellTrait>;
        using CellType = Cell<VertexND, CellND, HalfEdgeTrait, VertexTrait, CellTrait>;
        using EdgeType = Edge<VertexND, CellND, HalfEdgeTrait, VertexTrait, CellTrait>;
        using HalfEdgeType = HalfEdge<VertexND, CellND, HalfEdgeTrait, VertexTrait, CellTrait>;
        using MeshType = Mesh<VertexND, CellND, HalfEdgeTrait, VertexTrait, CellTrait>;

    public:
        typedef std::weak_ptr<HalfEdgeType> halfedge_ptr;
    public:
        std::pair<halfedge_ptr, halfedge_ptr> halfedge_pair;
    };
}

#endif //PMESH_EDGE_H
