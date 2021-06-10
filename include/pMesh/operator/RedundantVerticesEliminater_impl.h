/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/6
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_REDUNDANTVERTICESELIMINATER_IMPL
#define PMESH_REDUNDANTVERTICESELIMINATER_IMPL

#include <pMesh/operators/RedundantVerticesEliminater.h>

template<int VertexND, int CellND>
void pMesh::RedundantVerticesEliminater::operator()(Mesh<VertexND, CellND> &mesh){
    using std::vector;
    using std::map;
    auto old_points = mesh.vertices;
    auto old_cells = mesh.faces;
    mesh.vertices.clear();
    mesh.faces.clear();
    vector<vector<int>> triangles;
    map<int, int> old_2_new, new_2_old;
    for (auto &cell: old_cells) {
        Cell<CellND> new_cell;
        for (int i = 0; i < CellND; ++i) {
            auto p = cell[i];
            if (old_2_new.count(p) == 0) {
                old_2_new[p] = mesh.vertices.size();
                mesh.vertices.push_back(old_points[p]);
            }
            new_cell[i] = old_2_new[p];
        }
        mesh.faces.push_back(new_cell);
    }
    for(auto [o, n]: old_2_new){
        new_2_old[n] = o;
    }
}


#endif //PMESH_REDUNDANTVERTICESELIMINATER_IMPL
