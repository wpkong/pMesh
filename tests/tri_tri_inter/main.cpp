///**
// * ------------------------------------
// * @author: Weipeng Kong
// * @date: 2021/5/14
// * @email: yjxkwp@foxmail.com
// * @site: https://x86.design
// * @description:
// * ------------------------------------
//**/
//
//
//#define BOOST_TEST_DYN_LINK
//#define BOOST_TEST_MAIN
//
//#include <boost/test/unit_test.hpp>
//#include <boost/log/trivial.hpp>
//#include <boost/progress.hpp>
//
//#include "tri_tri_intersection.h"
//
//#include <pMesh/core/SurfaceMesh.h>
//#include <pMesh/io/adapters/DefaultReadAdapter.h>
//#include <pMesh/io/readers/STLReader.h>
//
//class BlockHalfEdgeReadAdapter : public pMesh::io::DefaultSurfaceReadAdapter<> {
//public:
//    explicit BlockHalfEdgeReadAdapter(MeshType &mesh) : pMesh::io::DefaultReadAdapter<>(mesh, true) {}
//
//    void end() {}
//};
//
//
//BOOST_AUTO_TEST_SUITE(test)
//
//    BOOST_AUTO_TEST_CASE(test_tri_tri_interset) {
//        using namespace pMesh;
//        io::fs_path shoe_path = "/Users/kwp/Downloads/triangle_mesh_insert/insole41_repair.stl";
//        io::fs_path inter_path = "/Users/kwp/Downloads/triangle_mesh_insert/PlateStructures12307.stl";
//        io::fs_path out_path = "/Users/kwp/Downloads/triangle_mesh_insert/out_inter.txt";
//
//        Mesh shoe;
//        Mesh inter;
//        io::STLReader(shoe_path) >> BlockHalfEdgeReadAdapter(shoe)();
//        io::STLReader(inter_path) >> BlockHalfEdgeReadAdapter(inter)();
//
//        BOOST_LOG_TRIVIAL(debug) << "[Shoe] Load " << shoe.v_size() << " vertices and " << shoe.f_size() << " faces";
//        BOOST_LOG_TRIVIAL(debug) << "[inter] Load " << inter.v_size() << " vertices and " << inter.f_size() << " faces";
//
//        int shoe_tri_n = shoe.f_size();
//        int inter_tri_n = inter.f_size();
//
//        std::vector<std::vector<double>> lines;
//        boost::progress_display progress(shoe_tri_n);
//
//#pragma omp parallel for
//        for (int i = 0; i < shoe_tri_n; ++i) {
//            const auto &cell2 = shoe.faces[i].attr.vertices;
//            const Point3d &p2 = shoe.vertices[cell2[0].id()].attr.coordinate,
//                    &q2 = shoe.vertices[cell2[1].id()].attr.coordinate,
//                    &r2 = shoe.vertices[cell2[2].id()].attr.coordinate;
//
//            for (int j = 0; j < inter_tri_n; ++j) {
//                const auto &cell1 = inter.faces[j].attr.vertices;
//                const Point3d &p1 = inter.vertices[cell1[0].id()].attr.coordinate,
//                        &q1 = inter.vertices[cell1[1].id()].attr.coordinate,
//                        &r1 = inter.vertices[cell1[2].id()].attr.coordinate;
//
//                int coplanar;
//                double source[3];
//                double target[3];
//
//                int rt = tri_tri_intersection_test_3d((double *) p1.data(), (double *) q1.data(), (double *) r1.data(),
//                                                      (double *) p2.data(), (double *) q2.data(), (double *) r2.data(),
//                                                      &coplanar, source, target);
////                std::cout << "rt: " << std::endl;
////                std::cout << "rt: " << rt << std::endl;
////                std::cout << "coplanar: " << coplanar <<std::endl;
////                std::cout << "source: " << source[0] << " " << source[1] << " " << source[2] << " " << std::endl;
////                std::cout << "target: " << target[0] << " " << target[1] << " " << target[2] << " " << std::endl;
//#pragma omp critical
//                {
//                    if (rt == 1 && coplanar == 0) {
//                        lines.push_back({source[0], source[1], source[2], target[0], target[1], target[2]});
//                    }
//                };
//            }
//#pragma omp critical
//            {
//                ++progress;
//            }
//        }
//
//        BOOST_LOG_TRIVIAL(debug) << "Extracted " << lines.
//
//                    size()
//
//                                 << " lines";
//        std::ofstream out(out_path.c_str());
//        for (
//            auto &line
//                : lines) {
//            for (
//                auto v
//                    : line) {
//                out << v << " ";
//            }
//            out <<
//                std::endl;
//        }
//        out.
//
//                close();
//
//    }
//
//BOOST_AUTO_TEST_SUITE_END()

int main(){

}