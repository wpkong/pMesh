/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/15
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_FACE_H
#define PMESH_FACE_H

#include <pMesh/Common.h>
#include <pMesh/core/Handle.h>

namespace pMesh {
    class BaseFace {
    };
}

namespace pMesh::Surface {
    class Face : public BaseFace {
    public:
        int id = -1;

    public:
        std::vector<VertexHandle> vertices;

    public:
        std::vector<HalfEdgeHandle> half_edges;
    };
}


namespace pMesh::Volume {
    class Face : public BaseFace {
    public:
        int id = -1;

    public:
        std::pair<HalfFaceHandle, HalfFaceHandle> half_face_pair;
    };
}


#endif //PMESH_FACE_H
