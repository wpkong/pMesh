/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/15
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_VERTEX_H
#define PMESH_VERTEX_H

#include <pMesh/Common.h>
#include <pMesh/core/Handle.h>

namespace pMesh{
    class BaseVertex{

    };
}

namespace pMesh::Surface{
    class Vertex: public BaseVertex{
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


namespace pMesh::Volume {
    class Vertex: public BaseVertex {
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
