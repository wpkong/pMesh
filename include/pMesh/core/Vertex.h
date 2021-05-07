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
#include <pMesh/core/Trait.h>
#include <pMesh/core/Decl.h>

namespace pMesh{
    template<int VertexND,
            int CellND,
            class HalfEdgeTrait,
            class VertexTrait,
            class CellTrait>
    class Vertex{
    public:
        PointNd<VertexND> coordinate;
        VectorNd<VertexND> normal;
        VertexTrait trait;
    };
}

#endif //PMESH_VERTEX_H
