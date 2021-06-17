/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/15
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_EXTRADATA_H
#define PMESH_EXTRADATA_H

#include <type_traits>
#include <pMesh/core/Cell.h>
#include <pMesh/core/ExtraData.h>
#include <pMesh/core/Vertex.h>
#include <pMesh/core/Face.h>
#include <pMesh/core/HalfFace.h>
#include <pMesh/core/Edge.h>
#include <pMesh/core/HalfEdge.h>
#include <pMesh/core/FieldWrapper.h>

namespace pMesh {
    template<class Field>
    struct BaseFieldExtraData {
        explicit BaseFieldExtraData(const Field &field) {};
    };
}

namespace pMesh::Surface {
    using BaseVertexExtraData = BaseFieldExtraData<Vertex>;

    using BaseFaceExtraData = BaseFieldExtraData<Face>;

    using BaseHalfEdgeExtraData = BaseFieldExtraData<HalfEdge>;

    using BaseEdgeExtraData = BaseFieldExtraData<Edge>;
}


namespace pMesh::Volume {
    using BaseVertexExtraData = BaseFieldExtraData<Vertex>;

    using BaseCellExtraData = BaseFieldExtraData<Cell>;

    using BaseHalfEdgeExtraData = BaseFieldExtraData<HalfEdge>;

    using BaseEdgeExtraData = BaseFieldExtraData<Edge>;

    using BaseFaceExtraData = BaseFieldExtraData<Face>;

    using BaseHalfFaceExtraData = BaseFieldExtraData<HalfFace>;
}


#endif //PMESH_EXTRADATA_H
