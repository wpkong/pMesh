/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/8
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_SURFACE_EDGE_H
#define PMESH_SURFACE_EDGE_H

#include <pMesh/Common.h>
#include <pMesh/core/ExtraData.h>
#include <pMesh/core/Surface/Decl.h>
#include <pMesh/core/Handle.h>

namespace pMesh{
    class Edge{
    public:
        int id = -1;

    public:
        VertexHandle va, vb;

        std::pair<EdgeHandle, EdgeHandle> halfedge_pair;
    };
}

#endif //PMESH_SURFACE_EDGE_H
