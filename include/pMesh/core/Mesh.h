/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/16
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_MESH_H
#define PMESH_MESH_H

#include <pMesh/Common.h>
#include <pMesh/core/ExtraData.h>
#include <pMesh/core/Vertex.h>

namespace pMesh{
    template<class VertexExtraData=Surface::BaseVertexExtraData>
    class BasePointCloudMesh{
    public:
        using VertexField = FieldWrapper<BaseVertex, VertexExtraData>;
    public:
        std::vector<VertexField> vertices;

    public:
        void move(const Vector3d &vec);

        void move(const Vector3d &dir, const double dis);
    };
}

#include <pMesh/core/Mesh_impl.h>

#endif //PMESH_MESH_H
