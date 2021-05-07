/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/7
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_DECL_H
#define PMESH_DECL_H

#include <pMesh/core/Trait.h>

namespace pMesh{
    template<int VertexND,
            int CellND,
            class HalfEdgeTrait = NullTrait,
            class VertexTrait = NullTrait,
            class CellTrait = NullTrait>
    class HalfEdge;

    template<int VertexND,
            int CellND,
            class HalfEdgeTrait = NullTrait,
            class VertexTrait = NullTrait,
            class CellTrait = NullTrait>
    using halfedge_sptr = std::shared_ptr<HalfEdge<VertexND, CellND, HalfEdgeTrait, VertexTrait, CellTrait>> ;

    template<int VertexND,
            int CellND,
            class HalfEdgeTrait = NullTrait,
            class VertexTrait = NullTrait,
            class CellTrait = NullTrait>
    using halfedge_wptr = std::weak_ptr<HalfEdge<VertexND, CellND, HalfEdgeTrait, VertexTrait, CellTrait>> ;
}

namespace pMesh{
    template<int VertexND,
            int CellND,
            class HalfEdgeTrait,
            class VertexTrait,
            class CellTrait>
    class Cell;

    template<int VertexND,
            int CellND,
            class HalfEdgeTrait,
            class VertexTrait,
            class CellTrait>
    using cell_sptr = std::shared_ptr<Cell<VertexND, CellND, HalfEdgeTrait, VertexTrait, CellTrait>>;

    template<int VertexND,
            int CellND,
            class HalfEdgeTrait,
            class VertexTrait,
            class CellTrait>
    using cell_wptr = std::weak_ptr<Cell<VertexND, CellND, HalfEdgeTrait, VertexTrait, CellTrait>>;
}

#endif //PMESH_DECL_H
