/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/15
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_EDGE_H
#define PMESH_EDGE_H

#include <pMesh/Common.h>
#include <pMesh/core/Handle.h>

namespace pMesh {
    class BaseEdge {
    };
}

namespace pMesh::Surface {
    class Edge : public BaseEdge {
    public:
        int id = -1;

    public:
        VertexHandle va, vb;

        std::pair<HalfEdgeHandle, HalfEdgeHandle> half_edge_pair;
    };
}


namespace pMesh::Volume {
    class Edge : public BaseEdge {
    public:
        int id = -1;

    public:
        VertexHandle va, vb;

        std::pair<HalfEdgeHandle, HalfEdgeHandle> half_edge_pair;
    };
}


#endif //PMESH_EDGE_H
