/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/16
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_MESH_IMPL_H
#define PMESH_MESH_IMPL_H

#include <pMesh/core/Mesh.h>

template<class VertexExtraData>
void pMesh::BasePointCloudMesh<VertexExtraData>::move(const Vector3d &vec){
    for(VertexField &v: vertices){
        v.attr->coordinate += vec;
    }
}


template<class VertexExtraData>
void pMesh::BasePointCloudMesh<VertexExtraData>::move(const Vector3d &dir, const double dis){
    this->move(dir.normalized() * dis);
}


#endif //PMESH_MESH_IMPL_H
