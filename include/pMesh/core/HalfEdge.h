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

namespace pMesh{
    class HalfEdge{
    public:
        size_t vertex_start;
        size_t vertex_end;
        
    };
}

#endif //PMESH_HALFEDGE_H
