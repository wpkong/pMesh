/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/7
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_SURFACEMESH_IMPL
#define PMESH_SURFACEMESH_IMPL

#include <pMesh/meshes/SurfaceMesh.h>
#include <pMesh/core/HalfEdge.h>
#include <pMesh/core/Edge.h>

template<int CellND, class HalfEdgeTrait, class VertexTrait, class CellTrait>
void pMesh::SurfaceMesh<CellND, HalfEdgeTrait, VertexTrait, CellTrait>::inflate_half_edge_datastructure() {
    // clear
    for(cell_sptr cell: this->cells){
        cell->half_edges.clear();
    }

    for (int cell_id = 0; cell_id < this->cells.size(); ++cell_id) {
        auto cell = this->cells[cell_id];
        std::shared_ptr<CellType> cell_p = std::make_shared<CellType>();
        for (int v_ind = 0; v_ind < cell->vertices.size(); ++v_ind) {
            std::shared_ptr<EdgeType> edge_p = std::make_shared<EdgeType>();

        }
    }
}

#endif //PMESH_SURFACEMESH_IMPL
