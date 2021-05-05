/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/5
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_TRIANGLEMESHOPERATORS_H
#define PMESH_TRIANGLEMESHOPERATORS_H

#include <pMesh/Common.h>
#include <pMesh/3d/TriangleMesh.h>

namespace pMesh::Operator{
    void compute_mesh_normals(Triangle3dMesh &mesh);
}

#endif //PMESH_TRIANGLEMESHOPERATORS_H
