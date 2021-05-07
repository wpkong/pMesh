/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/7
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description:  Support Half edge struct
 * ------------------------------------
**/

#ifndef PMESH_SURFACEMESH_H
#define PMESH_SURFACEMESH_H

#include <pMesh/Common.h>
#include <pMesh/core/Mesh.h>

namespace pMesh{
    template<int CellND>
    class SurfaceMesh: public Mesh<3, CellND>{

    };
}

#endif //PMESH_SURFACEMESH_H
