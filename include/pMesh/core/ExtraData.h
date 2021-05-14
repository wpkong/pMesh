/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/7
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_EXTRADATA_H
#define PMESH_EXTRADATA_H

#include <pMesh/core/Surface/Decl.h>
#include <type_traits>

namespace pMesh {
    class NullExtraData {
    };

    template<class Field>
    struct BaseFieldExtraData {
        explicit BaseFieldExtraData(const Field &field) {};
    };

    using BaseVertexExtraData = BaseFieldExtraData<Vertex>;

    using BaseCellExtraData = BaseFieldExtraData<Cell>;

    using BaseHalfEdgeExtraData = BaseFieldExtraData<HalfEdge>;

    using BaseEdgeExtraData = BaseFieldExtraData<Edge>;
}

#endif //PMESH_EXTRADATA_H
