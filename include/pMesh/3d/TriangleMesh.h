/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/4/28
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_TRIANGLEMESH_H
#define PMESH_TRIANGLEMESH_H

#include <pMesh/core/Mesh.h>
#include <vector>

namespace pMesh{
    class Triangle3dMesh: public Mesh<3, 3>{
    public:
        std::vector<Vector3d> cell_normals;

    };
}

#endif //PMESH_TRIANGLEMESH_H
