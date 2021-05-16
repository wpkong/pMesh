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
    public:
        Point3d coordinate;
        Vector3d normal;

    public:
        explicit BaseVertex(const Point3d&p): coordinate(p){};
    };
}

namespace pMesh::Surface{
    class Vertex: public BaseVertex{
    public:
        int id = -1;

    public:
        std::vector<HalfEdgeHandle> half_edge_in;
        std::vector<HalfEdgeHandle> half_edge_out;

    public:
        explicit Vertex(int id, const Point3d &coordinate): id(id), BaseVertex(coordinate) {};
    };
}


namespace pMesh::Volume {
    class Vertex: public BaseVertex {
    public:
        int id = -1;

    public:
        std::vector<HalfEdgeHandle> half_edge_in;
        std::vector<HalfEdgeHandle> half_edge_out;

    public:
        explicit Vertex(int id, const Point3d &coordinate): id(id), BaseVertex(coordinate) {};
    };
}

#endif //PMESH_VERTEX_H
