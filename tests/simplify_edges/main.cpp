/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/13
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#include <utility>
#include <pMesh/io/readers/BaseReader.h>
#include <pMesh/io/readers/VTKReader.h>
#include <pMesh/core/ExtraData.h>
#include <pMesh/io/adapters/DefaultReadAdapter.h>
#include <pMesh/core/SurfaceMesh.h>
#include <pMesh/io/writers/VFWriter.h>
#include <fstream>
#include <sstream>
#include "preprocess.h"
#include "utils.h"

int main() {
//        preprocess();
//        return 0;
    using namespace pMesh;
    io::fs_path in_vtk_path;
    io::fs_path out_v_path;
    io::fs_path out_f_path;
    io::fs_path out_vtk_path;

//    in_vtk_path = "/Users/kwp/Downloads/allms12307_info_test2/segments_info.vtk";
//    out_v_path = "/Users/kwp/Downloads/allms12307_info_test2/simple_segments_info_V.txt";
//    out_f_path = "/Users/kwp/Downloads/allms12307_info_test2/simple_segments_info_F.txt";
//    out_vtk_path = "/Users/kwp/Downloads/allms12307_info_test2/simple_segments_info.vtk";

    std::string name = "midsole_rescale0.8_egdes";
    bool length_fileter = true;

    in_vtk_path = "/Users/kwp/Downloads/未命名文件夹/" + name + ".vtk";
    out_v_path = "/Users/kwp/Downloads/未命名文件夹/" + name + "_V_sim.txt";
    out_f_path = "/Users/kwp/Downloads/未命名文件夹/" + name + "_F_sim.txt";
    out_vtk_path = "/Users/kwp/Downloads/未命名文件夹/" + name + "_sim.vtk";

    SurfaceMesh m;
    io::VTKReader(in_vtk_path) >> io::DefaultSurfaceReadAdapter(m)();
    BOOST_LOG_TRIVIAL(debug) << "Loaded points: " << m.v_size();
    BOOST_LOG_TRIVIAL(debug) << "Loaded faces: " << m.f_size();

    SurfaceMesh new_m;
    new_m.vertices = m.vertices;

    std::set<vertex_pair> edges;
    for (auto &cell: m.faces) {
        int a = cell.attr.vertices[0].id();
        int b = cell.attr.vertices[1].id();
        if (a > b) std::swap(a, b);
        edges.emplace(a, b);
    }
    auto chains = convert_edges_to_chains(edges);
    edges.clear();
    for (auto &chain: chains) {
        vector<int> chain_vec;
        chain_vec.reserve(chain.size() + 1);
        chain_vec.push_back(chain.front().first);
        for (int i = 0; i < chain.size(); ++i) {
            chain_vec.push_back(chain[i].second);
        }

        if (chain.size() > 1) {
            while (chain_vec.size() > 2){
                auto max_it = chain_vec.begin();
                double max_v = -100;
                for (auto it = std::next(chain_vec.begin()); it != chain_vec.end() && (it + 1) != chain_vec.end(); it++) {
                    const Point3d p1 = new_m.vertices[*(it - 1)].attr.coordinate;
                    const Point3d p0 = new_m.vertices[*it].attr.coordinate;
                    const Point3d p2 = new_m.vertices[*(it + 1)].attr.coordinate;
                    Vector3d v1 = (p0 - p1).normalized();
                    Vector3d v2 = (p2 - p0).normalized();
//                    BOOST_LOG_TRIVIAL(debug) << v1.dot(v2);
//                if (v1.dot(v2) >= 0.95) { // 平行
//                    it = chain_vec.erase(it);
//                } else {
//                    ++it;
//                }
                    double dot_v = v1.dot(v2);
                    if (dot_v >= max_v) { // 平行
                        max_it = it;
                        max_v = dot_v;
                    }
                }
                if(max_v >= 0.995){
                    chain_vec.erase(max_it);
                }else{
                    break;
                }
            }
        }

        for (int i = 1; i < chain_vec.size(); ++i) {
            int a = chain_vec[i - 1];
            int b = chain_vec[i];
            if (a == b) continue;
            if (a > b) std::swap(a, b);
            edges.emplace(a, b);
        }
    }

    for (auto &[a, b]: edges) {
        new_m.faces.emplace_back(
                Surface::Face{.vertices = {Surface::VertexHandle(a), Surface::VertexHandle(b)}});
    }

    new_m.compact_vertices();
    new_m.build_half_edge_structure();

    if(length_fileter){
        vector<typename SurfaceMesh<>::MeshType> meshes = new_m.split_into_meshes();
        BOOST_LOG_TRIVIAL(info) << "Split the mesh into " << meshes.size();

        new_m.clear();
        for(auto &mesh: meshes){
            double leng = 0;
            for(auto &ef: mesh.faces){
                auto a = ef.attr.vertices[0];
                auto b = ef.attr.vertices[1];
                leng += (mesh.vertex(a).coordinate - mesh.vertex(b).coordinate).squaredNorm();
            }
            BOOST_LOG_TRIVIAL(info) << "Length = " << leng;
            if(leng > 40) new_m += mesh;
        }
    }

    io::VTKWriter(3, out_vtk_path) << io::DefaultSurfaceWriteAdapter(new_m)();
    io::VFWriter(out_v_path, out_f_path) << io::DefaultSurfaceWriteAdapter(new_m)();
}
