/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/7
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_VOLUMEMESH_H
#define PMESH_VOLUMEMESH_H

#include <pMesh/core/Mesh.h>

namespace pMesh{
    template<int CellND, class HalfEdgeTrait=NullTrait,
            class VertexTrait=NullTrait,
            class CellTrait=NullTrait>
    class VolumeMesh: public Mesh<3, CellND, HalfEdgeTrait, VertexTrait, CellTrait>{

    };
}

#endif //PMESH_VOLUMEMESH_H
