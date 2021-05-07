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
#include <pMesh/core/Null.h>

namespace pMesh{
    template<int VertexND, class Trait=Null::NullTrait>
    class Vertex{
    public:
        PointNd<VertexND> coordinate;
        VectorNd<VertexND> normal;
        Trait trait;
    };
}

#endif //PMESH_VERTEX_H
