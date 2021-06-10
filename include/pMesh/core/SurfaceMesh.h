/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/15
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_SURFACEMESH_H
#define PMESH_SURFACEMESH_H

#include <pMesh/Common.h>
#include <pMesh/core/Mesh.h>
#include <pMesh/core/ExtraData.h>
#include <pMesh/core/Vertex.h>
#include <pMesh/core/Face.h>
#include <pMesh/core/Edge.h>
#include <pMesh/core/HalfEdge.h>
#include <pMesh/core/FieldWrapper.h>
#include <vector>
#include <array>

namespace pMesh {
    template<class VertexExtraData=Surface::BaseVertexExtraData,
            class HalfEdgeExtraData=Surface::BaseHalfEdgeExtraData,
            class EdgeExtraData = Surface::BaseEdgeExtraData,
            class FaceExtraData = Surface::BaseFaceExtraData>
    class SurfaceMesh : public BasePointCloudMesh<FieldWrapper<Surface::Vertex, VertexExtraData>>{
    public:
        using MeshType = SurfaceMesh<VertexExtraData, HalfEdgeExtraData, EdgeExtraData, FaceExtraData>;
        using Vertex = Surface::Vertex;
        using HalfEdge = Surface::HalfEdge;
        using Edge = Surface::Edge;
        using Face = Surface::Face;
        using VertexHandle = Surface::VertexHandle;
        using HalfEdgeHandle = Surface::HalfEdgeHandle;
        using EdgeHandle = Surface::EdgeHandle;
        using FaceHandle = Surface::FaceHandle;

        using VertexField = FieldWrapper<Surface::Vertex, VertexExtraData>;
        using HalfEdgeField = FieldWrapper<HalfEdge, HalfEdgeExtraData>;
        using EdgeField = FieldWrapper<Edge, EdgeExtraData>;
        using FaceField = FieldWrapper<Face, FaceExtraData>;

    public:
//        std::vector<VertexField> vertices;
        std::vector<HalfEdgeField> half_edges;
        std::vector<EdgeField> edges;
        std::vector<FaceField> faces;

    protected:
        bool half_edge_dirty = true;

    public:
        Vertex &vertex(const VertexHandle &handle) { return this->vertices.at(handle.id()).attr; };

        HalfEdge &half_edge(const HalfEdgeHandle &handle) { return half_edges.at(handle.id()).attr; }

        Edge &edge(const EdgeHandle &handle) { return edges.at(handle.id()).attr; }

        Face &face(const FaceHandle &handle) { return faces.at(handle.id()).attr; }

    public:
        VertexExtraData &vertex_data(const VertexHandle &handle) { return this->vertices.at(handle.id()).extra; };

        HalfEdgeExtraData &half_edge_data(const HalfEdgeHandle &handle) { return half_edges.at(handle.id()).extra; }

        EdgeExtraData &edge_data(const EdgeHandle &handle) { return edges.at(handle.id()).extra; }

        FaceExtraData &face_data(const FaceHandle &handle) { return faces.at(handle.id()).extra; }

    public:
        Vertex &attr(const VertexHandle &handle) { return this->vertices.at(handle.id()).attr; };

        HalfEdge &attr(const HalfEdgeHandle &handle) { return half_edges.at(handle.id()).attr; }

        Edge &attr(const EdgeHandle &handle) { return edges.at(handle.id()).attr; }

        Face &attr(const FaceHandle &handle) { return faces.at(handle.id()).attr; }

    public:
        VertexExtraData &data(const VertexHandle &handle) { return this->vertices.at(handle.id()).extra; }

        HalfEdgeExtraData &data(const HalfEdgeHandle &handle) { return half_edges.at(handle.id()).extra; }

        EdgeExtraData &data(const EdgeHandle &handle) { return edges.at(handle.id()).extra; }

        FaceExtraData &data(const FaceHandle &handle) { return faces.at(handle.id()).extra; }

    public:
        size_t v_size() const { return this->vertices.size(); }

        size_t f_size() const { return faces.size(); }

        size_t e_size() const { return edges.size(); }

    public:
        void clear_half_edge_structure();

        void build_half_edge_structure();

        /**
         * Discard unused vertices
         */
        void compact_vertices();

        /**
         * Split this mesh into separated mesh via its connectivity
         */
        std::vector<MeshType> split_into_meshes();

        void clear();

    public:
        MeshType &operator +=(MeshType mesh);
    };
};

#include <pMesh/core/SurfaceMesh_impl.h>

#endif //PMESH_SURFACEMESH_H
