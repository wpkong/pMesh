/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/13
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_PREPROCESS_H
#define PMESH_PREPROCESS_H

#include <boost/test/unit_test.hpp>
#include <boost/log/trivial.hpp>
#include <utility>
#include <pMesh/core/SurfaceMesh.h>
#include <pMesh/core/ExtraData.h>
#include <pMesh/io/readers/BaseReader.h>
#include <pMesh/io/adapters/DefaultReadAdapter.h>
#include <pMesh/io/adapters/DefaultWriteAdapter.h>
#include <pMesh/io/writers/VTKWriter.h>
#include <pMesh/io/writers/VFWriter.h>
#include <fstream>
#include <sstream>

namespace pMesh{
    class EdgeFormatReader: public io::BaseReader{
        io::fs_path path;
        double eps = 1e-3;
        std::vector<Point3d> vertices;
        std::set<std::pair<int, int>> edge_pairs;
    public:
        explicit EdgeFormatReader(io::fs_path path): path(std::move(path)){}
    public:
        inline double approximate(const double x) const {
            return std::fabs(x - round(x)) < eps ? (round(x) == -0.0 ? 0 : round(x)) : x;
        }

        int get_p_id(const Point3d &p, pMesh::io::ReadAdapter &adapter){
            volatile int found = -1;
            #pragma omp parallel for shared(found)
            for (int i = 0; i < vertices.size(); ++i) {
                if(found != -1) continue;
                double dis = (vertices[i] - p).lpNorm<2>();
                if(approximate(dis) == 0) found = i;
            }
            if(found == -1){
                vertices.push_back(p);
                adapter.feed_vertex(p);
                found = vertices.size() - 1;
            }
            return found;
        }

        bool operator >> (pMesh::io::ReadAdapter &adapter) override{
            std::fstream fs(this->path.c_str());
            if(not fs.is_open()) return false;
            adapter.start();
            std::string line;
            int cnt = 0;
            while (std::getline(fs, line)){
                std::cout << '\r' << cnt++;
                std::cout.flush();
                std::stringstream ss(line);
                Point3d p;
                ss >> p.x() >> p.y() >> p.z();
                int a = get_p_id(p, adapter);
                ss >> p.x() >> p.y() >> p.z();
                int b = get_p_id(p, adapter);
                if(a == b) continue;

                std::pair<int, int> ppp(std::min(a, b), std::max(a, b));
                if(this->edge_pairs.find(ppp) == this->edge_pairs.end()){
                    adapter.feed_collection({a, b});
                    this->edge_pairs.insert(ppp);
                }
            }
            std::cout << std::endl;
            std::cout << "Done." << std::endl;
//            adapter.end();
            return true;
        }
    };
}

void preprocess(){
    using namespace pMesh;
    io::fs_path in_path = "/Users/kwp/Downloads/allms12307_info_test2/allms12307_info_test2.txt";
    io::fs_path out_v_path = "/Users/kwp/Downloads/allms12307_info_test2/segments_info_V.txt";
    io::fs_path out_f_path = "/Users/kwp/Downloads/allms12307_info_test2/segments_info_F.txt";
    io::fs_path out_vtk_path = "/Users/kwp/Downloads/allms12307_info_test2/segments_info.vtk";

    SurfaceMesh m;
    EdgeFormatReader(in_path) >> io::DefaultSurfaceReadAdapter(m)();
    BOOST_LOG_TRIVIAL(debug) << "Loaded points: " << m.v_size();
    BOOST_LOG_TRIVIAL(debug) << "Loaded faces: " << m.f_size();

    io::VTKWriter(3, out_vtk_path) << io::DefaultSurfaceWriteAdapter(m)();
    io::VFWriter(out_v_path, out_f_path) << io::DefaultSurfaceWriteAdapter(m)();
}

#endif //PMESH_PREPROCESS_H
