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
#include <pMesh/core/Trait.h>
#include <pMesh/core/Vertex.h>
#include <pMesh/core/Cell.h>
#include <vector>
#include <array>

namespace pMesh {
    template<int VertexND,
            int CellND,
            class HalfEdgeTrait=NullTrait,
            class VertexTrait=NullTrait,
            class CellTrait=NullTrait>
    class Mesh {
    public:
        using VertexType = Vertex<VertexND, CellND, HalfEdgeTrait, VertexTrait, CellTrait>;
        using CellType = Cell<VertexND, CellND, HalfEdgeTrait, VertexTrait, CellTrait>;
        using HalfEdgeType = HalfEdge<VertexND, CellND, HalfEdgeTrait, VertexTrait, CellTrait>;

        using vertex_sptr = std::shared_ptr<VertexType>;
        using cell_sptr = std::shared_ptr<CellType>;

    public:
        std::vector<vertex_sptr> vertices;
        std::vector<cell_sptr> cells;
    };
};

#include <pMesh/core/Mesh.impl>

#endif //PMESH_MESH_H
