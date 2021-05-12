/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/7
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_HALFEDGE_H
#define PMESH_HALFEDGE_H

#include <pMesh/Common.h>
#include <pMesh/core/ExtraData.h>
#include <pMesh/core/Decl.h>
#include <pMesh/core/Handle.h>

namespace pMesh{
    class HalfEdge{
    public:
        int id = -1;
    public:
        VertexHandle vertex_start;
        VertexHandle vertex_end;
    public:
        HalfEdgeHandle opposite;
        HalfEdgeHandle next;
        HalfEdgeHandle prev;
        EdgeHandle edge;

    public:
        CellHandle cell;
    };
}

#endif //PMESH_HALFEDGE_H
