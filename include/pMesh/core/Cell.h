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
#include <pMesh/core/Trait.h>

namespace pMesh {
    template<int VertexND,
            int CellND,
            class HalfEdgeTrait,
            class VertexTrait,
            class CellTrait>
    class Cell {
    public:
        using VertexType = Vertex<VertexND, CellND, HalfEdgeTrait, VertexTrait, CellTrait>;
        using CellType = Cell<VertexND, CellND, HalfEdgeTrait, VertexTrait, CellTrait>;
        using EdgeType = Edge<VertexND, CellND, HalfEdgeTrait, VertexTrait, CellTrait>;
        using HalfEdgeType = HalfEdge<VertexND, CellND, HalfEdgeTrait, VertexTrait, CellTrait>;
        using MeshType = Mesh<VertexND, CellND, HalfEdgeTrait, VertexTrait, CellTrait>;

        using Cell_Vertex_T = std::array<size_t, CellND>;
        using halfedge_sptr = std::shared_ptr<HalfEdgeType>;
    public:
        Cell_Vertex_T vertices;

    public:
        std::vector<halfedge_sptr> half_edges;

    public:
        CellTrait trait;
    };
}

#endif //PMESH_CELL_H
