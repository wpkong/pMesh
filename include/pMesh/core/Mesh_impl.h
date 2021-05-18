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
#include <limits>

template<class VertexField>
void pMesh::BasePointCloudMesh<VertexField>::move(const Vector3d &vec){
    for(VertexField &v: vertices){
        v.attr->coordinate += vec;
    }
}


template<class VertexField>
void pMesh::BasePointCloudMesh<VertexField>::move(const Vector3d &dir, double dis){
    this->move(dir.normalized() * dis);
}

template<class VertexField>
std::array<double, 6> pMesh::BasePointCloudMesh<VertexField>::aabb() const {
    std::array<double, 6> aabb{
            std::numeric_limits<double>::max(),
            std::numeric_limits<double>::lowest(),
            std::numeric_limits<double>::max(),
            std::numeric_limits<double>::lowest(),
            std::numeric_limits<double>::max(),
            std::numeric_limits<double>::lowest()};
    for(const VertexField &v: this->vertices){
        const auto &p = v.attr->coordinate;
        aabb[0] = std::min(p.x(), aabb[0]);
        aabb[1] = std::max(p.x(), aabb[1]);

        aabb[2] = std::min(p.y(), aabb[2]);
        aabb[3] = std::max(p.y(), aabb[3]);

        aabb[4] = std::min(p.z(), aabb[4]);
        aabb[5] = std::max(p.z(), aabb[5]);
    }

    return aabb;
}


template<class VertexField>
std::vector<VertexField> pMesh::BasePointCloudMesh<VertexField>::copy_vertices(){
    std::vector<VertexField> new_vs;
    // TODO: check the necessity
//    new_vs.reserve(this->vertices.size());
//    std::transform(this->vertices.begin(), this->vertices.end(), std::back_inserter(new_vs), [](const VertexField &vf){
//        return vf.copy();
//    });
    return new_vs;
}

#endif //PMESH_MESH_IMPL_H
