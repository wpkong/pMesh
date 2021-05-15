/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/15
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_HALFEDGE_H
#define PMESH_HALFEDGE_H

#include <pMesh/Common.h>
#include <pMesh/core/Handle.h>

namespace pMesh {
    class BaseHalfEdge {
    };
}

namespace pMesh::Surface {
    class HalfEdge : public BaseHalfEdge {
    public:
        int id = -1;
    public:
        VertexHandle vertex_start;
        VertexHandle vertex_end;
    public:
        HalfEdgeHandle twin;
        HalfEdgeHandle next;
        HalfEdgeHandle prev;
        EdgeHandle edge;

    public:
        FaceHandle face;
    };
}

namespace pMesh::Volume {
    class HalfEdge : public BaseHalfEdge {
    public:
        int id = -1;
    public:
        VertexHandle vertex_start;
        VertexHandle vertex_end;
    public:
        HalfEdgeHandle twin;
        HalfEdgeHandle next;
        HalfEdgeHandle prev;
        EdgeHandle edge;

    public:
        HalfFaceHandle half_face;
    };
}


#endif //PMESH_HALFEDGE_H
