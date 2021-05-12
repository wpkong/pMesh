/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/5
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_MESH_IMPL
#define PMESH_MESH_IMPL

#include <pMesh/Common.h>
#include <pMesh/core/Mesh.h>
#include <boost/assert.hpp>
#include <map>

template<class VertexExtraData,
        class HalfEdgeExtraData,
        class EdgeExtraData,
        class CellExtraData>
void pMesh::Mesh<VertexExtraData, HalfEdgeExtraData, EdgeExtraData, CellExtraData>::
build_half_edge_structure() {
    this->half_edges.clear();
    this->edges.clear();

    std::map<std::pair<int, int>, int> edge_map;  // <min, max>, idx

    for (size_t i = 0; i < this->vertices.size(); ++i) {
        auto vertex = this->vertices[i];
        vertex.attr.id = i;
        vertex.attr.half_edge_in.clear();
        vertex.attr.half_edge_out.clear();
    }

    for (size_t i = 0; i < this->cells.size(); ++i) {
        auto cell = this->cells[i];
        cell.attr.half_edges.clear();
        cell.attr.id = i;
        for (int j = 0; j < cell.attr.vertices.size(); ++j) {
            int a = cell.attr.vertices[j];
            int b = cell.attr.vertices[(j + 1) % cell.attr.vertices.size()];

            HalfEdge he;
            he.id = this->half_edges.size();
            he.cell = cell.attr.id;
            he.vertex_start = a;
            he.vertex_end = b;

            std::pair<int, int> edge_pair(std::min(a, b), std::max(a, b));
            auto edge_fd = edge_map.find(edge_pair);
            Edge *e_ptr;
            if(edge_fd == edge_map.end()){
                Edge e;
                e.va = edge_pair.first;
                e.vb = edge_pair.second;
                e.id = this->edges.size();
                // update
                this->edges.push_back(e);
                edge_map[edge_pair] = e.id;
                e_ptr = &(this->edges.back());
                e_ptr->halfedge_pair.first = he.id;

            }else{
                e_ptr = &(this->edges[*edge_fd]);
                BOOST_ASSERT_MSG(e_ptr->halfedge_pair.second.id() == -1,
                                 "Invalid mesh: more than 2 half edges share one edge.");
                e_ptr->halfedge_pair.second = he.id;
            }
            he.edge = e_ptr->id;
            vertex(a).half_edge_out.emplace_back(he.id);
            vertex(b).half_edge_in.emplace_back(he.id);
            cell.attr.half_edges.emplace_back(he.id);

            // update
            this->half_edges.push_back(he);
        }

        int he_n = cell.attr.half_edges.size();
        for (int i = 0; i < he_n; ++i){
            auto he = cell.attr.half_edges[i];
            auto prev_i = cell.attr.half_edges[(i + he_n - 1) % he_n];
            auto next_i = cell.attr.half_edges[(i + he_n + 1) % he_n];
            half_edge(he).prev = half_edge(prev_i).id;
            half_edge(he).next = half_edge(next_i).id;
        }
    }
}

#endif //PMESH_MESH_IMPL
