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

#include <pMesh/io/adapters/ReadAdapter.h>
#include <pMesh/core/Surface/Mesh.h>

namespace pMesh::io {
    template<class VertexExtraData=BaseVertexExtraData,
            class HalfEdgeExtraData=BaseHalfEdgeExtraData,
            class EdgeExtraData = BaseEdgeExtraData,
            class CellExtraData = BaseCellExtraData>
    class DefaultReadAdapter : public ReadAdapter {
    public:
        typedef Mesh<VertexExtraData, HalfEdgeExtraData, EdgeExtraData, CellExtraData> MeshType;
    protected:
        MeshType &mesh;
    public:
        explicit DefaultReadAdapter(MeshType &mesh) : mesh(mesh) {}

        void start() {
            this->mesh.vertices.clear();
            this->mesh.half_edges.clear();
            this->mesh.edges.clear();
            this->mesh.cells.clear();
        }

        void feed_vertex(const Point3d &v) {
            int v_id = this->mesh.v_size();
            this->mesh.vertices.emplace_back(Vertex{.id = v_id, .coordinate = v});
        }

        void feed_cell(const std::vector<int> &c) {
            int c_id = this->mesh.c_size();
            Cell cell{.id = c_id};
            std::transform(c.begin(), c.end(), std::back_inserter(cell.vertices), [](int v){
                return VertexHandle(v);
            });
            this->mesh.cells.emplace_back(cell);
        }

        void end() {
            this->mesh.build_half_edge_structure();
        }
    };
}

#endif //PMESH_DEFAULTREADADAPTER_H
