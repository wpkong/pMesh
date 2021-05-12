/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/4/28
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
#include <pMesh/core/Cell.h>
#include <pMesh/core/Edge.h>
#include <pMesh/core/HalfEdge.h>
#include <pMesh/core/FieldWrapper.h>
#include <vector>
#include <array>

namespace pMesh {
    template<class VertexExtraData=BaseVertexExtraData,
            class HalfEdgeExtraData=BaseHalfEdgeExtraData,
            class EdgeExtraData = BaseEdgeExtraData,
            class CellExtraData = BaseCellExtraData>
    class Mesh {
    public:
        using VertexField = FieldWrapper<Vertex, VertexExtraData>;
        using HalfEdgeField = FieldWrapper<HalfEdge, HalfEdgeExtraData>;
        using EdgeField = FieldWrapper<Edge, EdgeExtraData>;
        using CellField = FieldWrapper<Cell, CellExtraData>;

    public:
        std::vector<VertexField> vertices;
        std::vector<HalfEdgeField> half_edges;
        std::vector<EdgeField> edges;
        std::vector<CellField> cells;

    public:
        Vertex &vertex(const VertexHandle &handle) { return vertices.at(handle).field; };
        HalfEdge &half_edge(const HalfEdgeHandle &handle) { return half_edges.at(handle).field; }
        Edge &edge(const EdgeHandle &handle) { return edges.at(handle).field; }
        Cell &cell(const CellHandle &handle){ return cells.at(handle).field; }

    public:
        VertexExtraData &vertex_data(const VertexHandle &handle) { return vertices.at(handle).extra; };
        HalfEdgeExtraData &half_edge_data(const HalfEdgeHandle &handle) { return half_edges.at(handle).extra; }
        EdgeExtraData &edge_data(const EdgeHandle &handle) { return edges.at(handle).extra; }
        CellExtraData &cell_data(const CellHandle &handle){ return cells.at(handle).extra; }

    public:
        Vertex &attr(const VertexHandle &handle) { return vertices.at(handle.id()).attr; };
        HalfEdge &attr(const HalfEdgeHandle &handle) { return half_edges.at(handle.id()).attr; }
        Edge &attr(const EdgeHandle &handle) { return edges.at(handle.id()).attr; }
        Cell &attr(const CellHandle &handle){ return cells.at(handle.id()).attr; }

    public:
        VertexExtraData &data(const VertexHandle &handle) { return vertices.at(handle).extra; }
        HalfEdgeExtraData &data(const HalfEdgeHandle &handle) { return half_edges.at(handle).extra; }
        EdgeExtraData &data(const EdgeHandle &handle){ return edges.at(handle).extra; }
        CellExtraData &data(const CellHandle &handle){ return cells.at(handle).extra; }

    public:
        size_t v_size(){ return vertices.size(); }
        size_t c_size(){ return cells.size(); }
        size_t e_size(){ return edges.size(); }

    public:
        void build_half_edge_structure();
    };
};

#include <pMesh/core/Mesh_impl.h>

#endif //PMESH_MESH_H
