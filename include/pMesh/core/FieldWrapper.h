/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/12
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_FIELDWRAPPER_H
#define PMESH_FIELDWRAPPER_H

#include <pMesh/core/Surface/Decl.h>
#include <pMesh/core/ExtraData.h>

namespace pMesh{
    template<class Field, class ExtraData>
    struct FieldWrapper{
        Field attr;
        ExtraData extra;

        explicit FieldWrapper(const Field &attr): attr(attr), extra(attr){}
    };

    template<class VertexExtraData>
    using VertexWrapper = FieldWrapper<Vertex, VertexExtraData>;

    template<class HalfEdgeExtraData>
    using HalfEdgeWrapper = FieldWrapper<HalfEdge, HalfEdgeExtraData>;

    template<class EdgeExtraData>
    using EdgeWrapper = FieldWrapper<Edge, EdgeExtraData>;

    template<class CellExtraData>
    using CellWrapper = FieldWrapper<Cell, CellExtraData>;
}

#endif //PMESH_FIELDWRAPPER_H
