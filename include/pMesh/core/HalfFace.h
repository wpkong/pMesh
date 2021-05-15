/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/15
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_HALFFACE_H
#define PMESH_HALFFACE_H

#include <pMesh/Common.h>
#include <pMesh/core/Handle.h>

namespace pMesh{
    class BaseHalfFace{};
}

namespace pMesh::Volume{
    class HalfFace: public BaseHalfFace{
    public:
        int id = -1;
    public:
        std::vector<HalfEdgeHandle> half_edges;

    public:
        HalfFaceHandle twin;

    public:
        FaceHandle face;
        CellHandle cell;
    };
}

#endif //PMESH_HALFFACE_H
