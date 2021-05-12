/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/7
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_VERTEX_H
#define PMESH_VERTEX_H

#include <pMesh/Common.h>
#include <pMesh/core/ExtraData.h>
#include <pMesh/core/Decl.h>
#include <pMesh/core/Handle.h>

namespace pMesh{
    class Vertex{
    public:
        int id = -1;

    public:
        Point3d coordinate;
        Vector3d normal;
    public:
        std::vector<HalfEdgeHandle> half_edge_in;
        std::vector<HalfEdgeHandle> half_edge_out;
    };
}

#endif //PMESH_VERTEX_H
