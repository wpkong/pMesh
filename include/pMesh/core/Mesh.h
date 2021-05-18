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
    template<class VertexField>
    class BasePointCloudMesh{
    public:
        std::vector<VertexField> vertices;

    public:
        void move(const Vector3d &vec);

        void move(const Vector3d &dir, double dis);

        std::array<double, 6> aabb() const;

        std::vector<VertexField> copy_vertices();
    };
}

#include <pMesh/core/Mesh_impl.h>

#endif //PMESH_MESH_H
