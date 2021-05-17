/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/13
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>
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

BOOST_AUTO_TEST_SUITE(test)

    BOOST_AUTO_TEST_CASE(simplify_edges) {
        preprocess();
        return;
        using namespace pMesh;
        io::fs_path in_v_path = "/Users/kwp/Downloads/segments_info/segments_info_V.txt";
        io::fs_path in_f_path = "/Users/kwp/Downloads/segments_info/segments_info_F.txt";
        io::fs_path in_vtk_path = "/Users/kwp/Downloads/allms12307_info_test2/segments_info.vtk";

        io::fs_path out_v_path = "/Users/kwp/Downloads/allms12307_info_test2/simple_segments_info_V.txt";
        io::fs_path out_f_path = "/Users/kwp/Downloads/allms12307_info_test2/simple_segments_info_F.txt";

        io::fs_path out_vtk_path = "/Users/kwp/Downloads/allms12307_info_test2/simple_segments_info.vtk";

        SurfaceMesh m;
        io::VTKReader(in_vtk_path) >> io::DefaultSurfaceReadAdapter(m)();
        BOOST_LOG_TRIVIAL(debug) << "Loaded points: " << m.v_size();
        BOOST_LOG_TRIVIAL(debug) << "Loaded faces: " << m.f_size();


        SurfaceMesh new_m;
        new_m.vertices = m.vertices;

        std::set<vertex_pair> edges;
        for (auto &cell: m.faces) {
            edges.emplace(cell.attr->vertices[0], cell.attr->vertices[1]);
        }
        auto chains = convert_edges_to_chains(edges);
        for (auto &chain: chains) {
            vector<int> chain_vec;
            chain_vec.reserve(chain.size() + 1);
            chain_vec.push_back(chain.front().first);
            for (int i = 0; i < chain.size(); ++i) {
                chain_vec.push_back(chain[i].second);
            }
            if (chain.size() > 1) {
                for (auto it = std::next(chain_vec.begin()); it != chain_vec.end() && (it + 1) != chain_vec.end();) {
                    const Point3d p1 = new_m.vertices[*(it - 1)].attr->coordinate;
                    const Point3d p0 = new_m.vertices[*it].attr->coordinate;
                    const Point3d p2 = new_m.vertices[*(it + 1)].attr->coordinate;
                    Vector3d v1 = (p0 - p1).normalized();
                    Vector3d v2 = (p2 - p0).normalized();
//                    BOOST_LOG_TRIVIAL(debug) << v1.dot(v2);
                    if (v1.dot(v2) >= 0.9) { // 平行
                        it = chain_vec.erase(it);
                    } else {
                        ++it;
                    }
                }
            }

            for (int i = 1; i < chain_vec.size(); ++i) {
                new_m.faces.emplace_back(
                        Surface::Face{.vertices = {Surface::VertexHandle(chain_vec[i - 1]), Surface::VertexHandle(chain_vec[i])}});
            }
        }

        std::deque<int> q;

        io::VTKWriter(3, out_vtk_path) << io::DefaultSurfaceWriteAdapter(new_m)();
        io::VFWriter(out_v_path, out_f_path) << io::DefaultSurfaceWriteAdapter(new_m)();
    }

BOOST_AUTO_TEST_SUITE_END()