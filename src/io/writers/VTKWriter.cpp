/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/13
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#include <pMesh/io/writers/VTKWriter.h>

inline double approximate(const double x, const double eps) {
    return std::fabs(x - round(x)) < eps ? (round(x) == -0.0 ? 0 : round(x)) : x;
}

pMesh::io::VTKWriter::VTKWriter(int type, const pMesh::io::fs_path &path) : type(type), path(path) {

}

bool pMesh::io::VTKWriter::operator<<(pMesh::io::WriteAdapter &adapter) {
    std::ofstream out(path.c_str());
    if (not out.is_open() or out.fail()) return false;
    adapter.start();
    out << "# vtk DataFile Version 3.0\n"
           "Volume Mesh\n"
           "ASCII\n"
           "DATASET UNSTRUCTURED_GRID\n";

    out << "POINTS " << adapter.request_number_of_vertices() << " float\n";
    Point3d p;
    while (adapter.request_vertex(p)) {
        for (int i = 0; i < 3; ++i) {
            out << approximate(p(i), this->eps) << " ";
        }
        out << std::endl;
    }
    size_t n_cells = adapter.request_number_of_collections();

    if (n_cells != 0) {
        std::vector<int> collection;
        adapter.request_collection(collection);
        out << "CELLS " << n_cells << " " << n_cells * (collection.size() + 1) << std::endl;
        // ---- first collection ----
        out << collection.size();
        for (auto v: collection) {
            out << " " << v;
        }
        out << std::endl;
        // --------------------
        while (adapter.request_collection(collection)) {
            out << collection.size();
            for (auto v: collection) {
                out << " " << v;
            }
            out << std::endl;
        }
        out << "CELL_TYPES " << n_cells << "\n";
        for (size_t i = 0; i < n_cells; ++i) {
            out << type << std::endl;
        }
    }
    adapter.end();
    return true;
}
