/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/12
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_DEFAULTADAPTER_H
#define PMESH_DEFAULTADAPTER_H

#include <pMesh/io/adapters/IOAdapter.h>
#include <pMesh/core/Mesh.h>

namespace pMesh::io {
    template<class VertexExtraData,
            class HalfEdgeExtraData,
            class EdgeExtraData,
            class CellExtraData>
    class DefaultAdapter : public IOAdapter {
    private:
        Mesh<VertexExtraData, HalfEdgeExtraData, EdgeExtraData, CellExtraData> &mesh;
    public:
        void start() override {
            this->mesh.vertices.clear();
            this->mesh.half_edges.clear();
            this->mesh.edges.clear();
            this->mesh.cells.clear();
        }

        void feed_vertex(const Point3d &v) override {
            int v_id = this->mesh.v_size();
            this->mesh.vertices.emplace_back({.id = v_id, .coordinate = v});
        }

        void feed_cell(const std::vector<int> &c) override {
            int c_id = this->mesh.c_size();
            this->mesh.cells.emplace_back({.id = c_id, .vertices = c});
        }

        void end() override {
            this->mesh.build_half_edge_structure();
        }
    };
}

#endif //PMESH_DEFAULTADAPTER_H
