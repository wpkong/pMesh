/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/15
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_VOLUMEMESH_H
#define PMESH_VOLUMEMESH_H

#include <pMesh/Common.h>
#include <pMesh/core/ExtraData.h>
#include <pMesh/core/Vertex.h>
#include <pMesh/core/Face.h>
#include <pMesh/core/Edge.h>
#include <pMesh/core/Cell.h>
#include <pMesh/core/HalfFace.h>
#include <pMesh/core/HalfEdge.h>
#include <pMesh/core/FieldWrapper.h>
#include <vector>
#include <array>

namespace pMesh {
    template<class VertexExtraData=Volume::BaseVertexExtraData,
            class HalfEdgeExtraData=Volume::BaseHalfEdgeExtraData,
            class EdgeExtraData = Volume::BaseEdgeExtraData,
            class HalfFaceExtraData = Volume::BaseHalfFaceExtraData,
            class FaceExtraData = Volume::BaseFaceExtraData,
            class CellExtraData = Volume::BaseCellExtraData
    >
    class VolumeMesh {
    public:
        using Vertex = Volume::Vertex;
        using HalfEdge = Volume::HalfEdge;
        using Edge = Volume::Edge;
        using Face = Volume::Face;
        using HalfFace = Volume::HalfFace;
        using Cell = Volume::Cell;

        using VertexHandle = Volume::VertexHandle;
        using HalfEdgeHandle = Volume::HalfEdgeHandle;
        using EdgeHandle = Volume::EdgeHandle;
        using HalfFaceHandle = Volume::HalfFaceHandle;
        using FaceHandle = Volume::FaceHandle;
        using CellHandle = Volume::CellHandle;

        using VertexField = FieldWrapper<Vertex, VertexExtraData>;
        using HalfEdgeField = FieldWrapper<HalfEdge, HalfEdgeExtraData>;
        using EdgeField = FieldWrapper<Edge, EdgeExtraData>;
        using HalfFaceField = FieldWrapper<HalfFace, HalfFace>;
        using FaceField = FieldWrapper<Face, FaceExtraData>;
        using CellField = FieldWrapper<Cell, CellExtraData>;

    public:
        std::vector<VertexField> vertices;
        std::vector<HalfEdgeField> half_edges;
        std::vector<EdgeField> edges;
        std::vector<HalfFaceField> half_faces;
        std::vector<FaceField> faces;
        std::vector<CellField> cells;

    public:
        Vertex &vertex(const VertexHandle &handle) { return vertices.at(handle.id()).attr; };

        HalfEdge &half_edge(const HalfEdgeHandle &handle) { return half_edges.at(handle.id()).attr; }

        Edge &edge(const EdgeHandle &handle) { return edges.at(handle.id()).attr; }

        HalfFace &half_face(const HalfFaceHandle &handle) { return half_faces.at(handle.id()).attr; }

        Face &face(const FaceHandle &handle) { return faces.at(handle.id()).attr; }

        Cell &cell(const CellHandle &handle) { return cells.at(handle.id()).attr; }

    public:
        VertexExtraData &vertex_data(const VertexHandle &handle) { return vertices.at(handle.id()).extra; };

        HalfEdgeExtraData &half_edge_data(const HalfEdgeHandle &handle) { return half_edges.at(handle.id()).extra; }

        EdgeExtraData &edge_data(const EdgeHandle &handle) { return edges.at(handle.id()).extra; }

        HalfFaceExtraData &half_face_data(const HalfFaceHandle &handle) { return half_faces.at(handle.id()).extra; }

        FaceExtraData &face_data(const FaceHandle &handle) { return faces.at(handle.id()).extra; }

        CellExtraData &cell_data(const CellHandle &handle) { return cells.at(handle.id()).extra; }

    public:
        Vertex &attr(const VertexHandle &handle) { return vertices.at(handle.id()).attr; };

        HalfEdge &attr(const HalfEdgeHandle &handle) { return half_edges.at(handle.id()).attr; }

        HalfFace &attr(const HalfFaceHandle &handle) { return half_faces.at(handle.id()).attr; }

        Edge &attr(const EdgeHandle &handle) { return edges.at(handle.id()).attr; }

        Face &attr(const FaceHandle &handle) { return faces.at(handle.id()).attr; }

        Cell &attr(const CellHandle &handle) { return cells.at(handle.id()).attr; }

    public:
        VertexExtraData &data(const VertexHandle &handle) { return vertices.at(handle.id()).extra; }

        HalfEdgeExtraData &data(const HalfEdgeHandle &handle) { return half_edges.at(handle.id()).extra; }

        HalfFaceExtraData &data(const HalfFaceHandle &handle) { return half_faces.at(handle.id()).extra; }

        EdgeExtraData &data(const EdgeHandle &handle) { return edges.at(handle.id()).extra; }

        FaceExtraData &data(const FaceHandle &handle) { return faces.at(handle.id()).extra; }

        CellExtraData &data(const CellHandle &handle) { return cells.at(handle.id()).extra; }

    public:
        size_t v_size() const { return vertices.size(); }

        size_t f_size() const { return faces.size(); }

        size_t e_size() const { return edges.size(); }

        size_t c_size() const { return cells.size(); }

    public:
        void clear_half_face_structure();

        virtual void build_half_face_structure() = 0;
    };
};

#include <pMesh/core/VolumeMesh_impl.h>

#endif //PMESH_VOLUMEMESH_H
