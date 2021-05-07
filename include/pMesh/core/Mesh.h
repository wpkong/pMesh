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
#include <pMesh/core/HalfEdge.h>
#include <vector>
#include <array>

namespace pMesh{
    class DefaultMeshMeta{

    };
}

namespace pMesh {
    template<int VertexND,
            int CellND,
            class HalfEdgeTrait,
            class VertexTrait,
            class CellTrait>
    class Mesh {
    public:
        using VertexType = Vertex<VertexND, CellND, HalfEdgeTrait, VertexTrait, CellTrait>;
        using CellType = Cell<VertexND, CellND, HalfEdgeTrait, VertexTrait, CellTrait>;
        using EdgeType = Edge<VertexND, CellND, HalfEdgeTrait, VertexTrait, CellTrait>;
        using HalfEdgeType = HalfEdge<VertexND, CellND, HalfEdgeTrait, VertexTrait, CellTrait>;
        using MeshType = Mesh<VertexND, CellND, HalfEdgeTrait, VertexTrait, CellTrait>;


    public:
        using vertex_sptr = std::shared_ptr<VertexType>;
        using cell_sptr = std::shared_ptr<CellType>;

    public:
        std::vector<vertex_sptr> vertices;
        std::vector<cell_sptr> cells;
    };
};

#include <pMesh/core/Mesh_impl.h>

#endif //PMESH_MESH_H
