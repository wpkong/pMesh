/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/15
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_FIELDWRAPPER_H
#define PMESH_FIELDWRAPPER_H

#include <type_traits>
#include <pMesh/core/Vertex.h>
#include <pMesh/core/Cell.h>
#include <pMesh/core/Edge.h>
#include <pMesh/core/Face.h>
#include <pMesh/core/HalfEdge.h>
#include <pMesh/core/HalfFace.h>

namespace pMesh {
    template<class Field, class ExtraData>
    struct FieldWrapper{
        Field attr;
        ExtraData extra;

        explicit FieldWrapper(const Field &attr): attr(attr), extra(attr){}
    };
}


namespace pMesh::Surface{
    template<class VertexExtraData>
    using VertexWrapper = FieldWrapper<Vertex, VertexExtraData>;

    template<class HalfEdgeExtraData>
    using HalfEdgeWrapper = FieldWrapper<HalfEdge, HalfEdgeExtraData>;

    template<class EdgeExtraData>
    using EdgeWrapper = FieldWrapper<Edge, EdgeExtraData>;

    template<class CellExtraData>
    using CellWrapper = FieldWrapper<Face, CellExtraData>;
}


#endif //PMESH_FIELDWRAPPER_H
