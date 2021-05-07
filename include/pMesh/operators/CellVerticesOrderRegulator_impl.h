/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/6
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_CELLVERTICESORDERREGULATOR_IMPL
#define PMESH_CELLVERTICESORDERREGULATOR_IMPL

#include <pMesh/operators/CellVerticesOrderRegulator.h>

pMesh::CellVerticesOrderRegulator::CellVerticesOrderRegulator(bool reverse): reverse(reverse) {}


template<class HalfEdgeTrait,
        class VertexTrait,
        class CellTrait>
void pMesh::CellVerticesOrderRegulator::operator()(Triangle3dMesh<HalfEdgeTrait, VertexTrait, CellTrait> &mesh)
    int cnt = 0;
    typedef std::pair<int, Edge> node_type;
    using std::vector;
    std::deque<node_type> Q;
    vector<bool> visited(mesh.cells.size(), false);

    //BFS
    for (int i = 0; i < mesh.cells.size(); ++i) {
        if (visited[i]) continue;
        visited[i] = true;

        for(auto nt: mesh.cells_kring[i]){
            if(visited[nt]) continue;

            Edge e = mesh.get_edge(i, nt);
            BOOST_ASSERT_MSG(
                    (e.first != -1 and e.second != -1),
                    "Return a pair of -1, please make sure this mesh whether is watertight.");
            Q.emplace_back(nt, e);
        }

        while (not Q.empty()){
            node_type node = Q.front();
            Q.pop_front();

            if(visited[node.first]) continue;
            visited[node.first] = true;

            // rev edges
            for (int j = 0; j < 3; ++j) {
                Edge re(mesh.cells[node.first][j], mesh.cells[node.first][(j+1)%3]);
                if(re == node.second){  // 有边同向
                    std::swap(mesh.cells[node.first][j], mesh.cells[node.first][(j+1)%3]);
                    cnt++;
                    break;
                }
            }

            // 加入邻边到队列
            for(auto nt: mesh.cells_kring[node.first]){
                if(visited[nt]) continue;

                Edge e = mesh.get_edge(node.first, nt);
                BOOST_ASSERT_MSG(
                        (e.first != -1 and e.second != -1),
                        "Return a pair of -1, please make sure this mesh whether is watertight.");
                Q.emplace_back(nt, e);
            }
        }
    }
    if(reverse){
        for (auto & cell : mesh.cells) {
            std::swap(cell[0], cell[1]);
        }
    }
}


#endif //PMESH_CELLVERTICESORDERREGULATOR_IMPL
