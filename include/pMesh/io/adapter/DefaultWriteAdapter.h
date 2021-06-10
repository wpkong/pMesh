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

#include <pMesh/io/adapter/WriteAdapter.h>
#include <pMesh/core/SurfaceMesh.h>
#include <pMesh/core/VolumeMesh.h>

namespace pMesh::io {
    template<class VertexExtraData,
            class HalfEdgeExtraData,
            class EdgeExtraData,
            class FaceExtraData>
    class DefaultSurfaceWriteAdapter : public WriteAdapter {
    public:
        using Vertex = Surface::Vertex;
        using Face = Surface::Face;
        using VertexHandle = Surface::VertexHandle;
        typedef SurfaceMesh<VertexExtraData, HalfEdgeExtraData, EdgeExtraData, FaceExtraData> MeshType;
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
            p = v_it->attr.coordinate;
            v_it++;
            return true;
        };

        bool request_collection(std::vector<int> &c) override {
            if(c_it == this->mesh.faces.end()) return false;
            c.clear();
            for(const VertexHandle &v: c_it->attr.vertices){
                c.push_back(v.id());
            }
            c_it++;
            return true;
        };

        void end() override {

        }
    };

    template<class VertexExtraData=Volume::BaseVertexExtraData,
            class HalfEdgeExtraData=Volume::BaseHalfEdgeExtraData,
            class EdgeExtraData = Volume::BaseEdgeExtraData,
            class HalfFaceExtraData = Volume::BaseHalfFaceExtraData,
            class FaceExtraData = Volume::BaseFaceExtraData,
            class CellExtraData = Volume::BaseCellExtraData>
    class DefaultVolumeWriteAdapter : public WriteAdapter {
    public:
        using Vertex = Volume::Vertex;
        using Cell = Volume::Cell;
        using VertexHandle = Volume::VertexHandle;
        typedef VolumeMesh<VertexExtraData, HalfEdgeExtraData, EdgeExtraData, HalfFaceExtraData, FaceExtraData, CellExtraData> MeshType;
        typename std::vector<typename MeshType::VertexField>::const_iterator v_it;
        typename std::vector<typename MeshType::CellField>::const_iterator c_it;

    private:
        MeshType &mesh;

    public:
        explicit DefaultVolumeWriteAdapter(MeshType &mesh) : mesh(mesh) {}

        void start() override {
            v_it = mesh.vertices.cbegin();
            c_it = mesh.cells.cbegin();
        }

        size_t request_number_of_vertices() override {
            return mesh.v_size();
        };

        size_t request_number_of_collections() override {
            return mesh.c_size();
        };

        bool request_vertex(Point3d &p) override {
            if(v_it == this->mesh.vertices.cend()) return false;
            p = v_it->attr.coordinate;
            v_it++;
            return true;
        };

        bool request_collection(std::vector<int> &c) override {
            if(c_it == this->mesh.cells.cend()) return false;
            c.clear();
            for(const VertexHandle &v: c_it->attr.vertices){
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
