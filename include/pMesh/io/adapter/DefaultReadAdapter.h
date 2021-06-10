/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/12
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_DEFAULTREADADAPTER_H
#define PMESH_DEFAULTREADADAPTER_H

#include <pMesh/io/adapter/ReadAdapter.h>
#include <pMesh/core/SurfaceMesh.h>
#include <pMesh/core/VolumeMesh.h>

namespace pMesh::io {
    template<class VertexExtraData=Surface::BaseVertexExtraData,
            class HalfEdgeExtraData=Surface::BaseHalfEdgeExtraData,
            class EdgeExtraData = Surface::BaseEdgeExtraData,
            class FaceExtraData = Surface::BaseFaceExtraData>
    class DefaultSurfaceReadAdapter : public ReadAdapter {
    public:
        typedef SurfaceMesh<VertexExtraData, HalfEdgeExtraData, EdgeExtraData, FaceExtraData> MeshType;
        using Vertex = Surface::Vertex;
        using Face = Surface::Face;
        using VertexHandle = Surface::VertexHandle;

    protected:
        bool build_half_ds = true;
        MeshType &mesh;
    public:
        explicit DefaultSurfaceReadAdapter(MeshType &mesh, bool build_half_ds = true) : mesh(mesh), build_half_ds(build_half_ds) {}

        void start() {
            this->mesh.vertices.clear();
            this->mesh.half_edges.clear();
            this->mesh.edges.clear();
            this->mesh.faces.clear();
        }

        void feed_vertex(const Point3d &v) {
            int v_id = this->mesh.v_size();
            this->mesh.vertices.emplace_back(Vertex(v_id, v));
        }

        void feed_collection(const std::vector<int> &c) {
            int c_id = this->mesh.f_size();
            Face face;
            face.id = c_id;
            std::transform(c.begin(), c.end(), std::back_inserter(face.vertices), [](int v){
                return VertexHandle(v);
            });
            this->mesh.faces.emplace_back(face);
        }

        void end() {
            if(build_half_ds){
                this->mesh.build_half_edge_structure();
            }
        }
    };


    template<class VertexExtraData=Volume::BaseVertexExtraData,
            class HalfEdgeExtraData=Volume::BaseHalfEdgeExtraData,
            class EdgeExtraData = Volume::BaseEdgeExtraData,
            class HalfFaceExtraData = Volume::BaseHalfFaceExtraData,
            class FaceExtraData = Volume::BaseFaceExtraData,
            class CellExtraData = Volume::BaseCellExtraData>
    class DefaultVolumeReadAdapter : public ReadAdapter {
    public:
        typedef VolumeMesh<VertexExtraData, HalfEdgeExtraData, EdgeExtraData, HalfFaceExtraData, FaceExtraData, CellExtraData> MeshType;
        using Vertex = Volume::Vertex;
        using Cell = Volume::Cell;
        using VertexHandle = Volume::VertexHandle;

    protected:
        bool build_half_ds = true;
        MeshType &mesh;
    public:
        explicit DefaultVolumeReadAdapter(MeshType &mesh, bool build_half_ds = true) : mesh(mesh), build_half_ds(build_half_ds) {}

        void start() {
            this->mesh.vertices.clear();
            this->mesh.half_edges.clear();
            this->mesh.edges.clear();
            this->mesh.cells.clear();
            this->mesh.half_faces.clear();
        }

        void feed_vertex(const Point3d &v) {
            int v_id = this->mesh.v_size();
            this->mesh.vertices.emplace_back(Vertex(v_id, v));
        }

        void feed_collection(const std::vector<int> &c) {
            int c_id = this->mesh.f_size();
            Cell cell;
            cell.id = c_id;
            std::transform(c.begin(), c.end(), std::back_inserter(cell.vertices), [](int v){
                return VertexHandle(v);
            });
            this->mesh.cells.emplace_back(cell);
        }

        void end() {
            if(build_half_ds){
                this->mesh.build_half_face_structure();
            }
        }
    };
}

#endif //PMESH_DEFAULTREADADAPTER_H
