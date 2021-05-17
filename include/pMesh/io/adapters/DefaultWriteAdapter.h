/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/12
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_DEFAULTWRITERADAPTER_H
#define PMESH_DEFAULTWRITERADAPTER_H

#include <pMesh/io/adapters/WriteAdapter.h>
#include <pMesh/core/SurfaceMesh.h>

namespace pMesh::io {
    template<class VertexExtraData,
            class HalfEdgeExtraData,
            class EdgeExtraData,
            class CellExtraData>
    class DefaultSurfaceWriteAdapter : public WriteAdapter {
    public:
        using Vertex = Surface::Vertex;
        using Face = Surface::Face;
        using VertexHandle = Surface::VertexHandle;
        typedef SurfaceMesh<VertexExtraData, HalfEdgeExtraData, EdgeExtraData, CellExtraData> MeshType;
        typename std::vector<typename MeshType::VertexField>::const_iterator v_it;
        typename std::vector<typename MeshType::FaceField>::const_iterator c_it;

    private:
        MeshType &mesh;

    public:
        explicit DefaultSurfaceWriteAdapter(MeshType &mesh) : mesh(mesh) {}

        void start() override {
            v_it = mesh.vertices.cbegin();
            c_it = mesh.faces.cbegin();
        }

        size_t request_number_of_vertices() override {
            return mesh.v_size();
        };

        size_t request_number_of_collections() override {
            return mesh.f_size();
        };

        bool request_vertex(Point3d &p) override {
            if(v_it == this->mesh.vertices.end()) return false;
            p = v_it->attr->coordinate;
            v_it++;
            return true;
        };

        bool request_collection(std::vector<int> &c) override {
            if(c_it == this->mesh.faces.end()) return false;
            c.clear();
            for(const VertexHandle &v: c_it->attr->vertices){
                c.push_back(v.id());
            }
            c_it++;
            return true;
        };

        void end() override {

        }
    };
}

#endif //PMESH_DEFAULTWRITERADAPTER_H
