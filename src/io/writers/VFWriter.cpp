/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/13
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#include <pMesh/io/writers/VFWriter.h>
#include <fstream>

pMesh::io::VFWriter::VFWriter(const pMesh::io::fs_path &v_path, const pMesh::io::fs_path &f_path): v_path(v_path), f_path(f_path) {

}

bool pMesh::io::VFWriter::operator<<(pMesh::io::WriteAdapter &adapter) {
    std::ofstream vfs(v_path.c_str());
    std::ofstream ffs(f_path.c_str());
    if(not vfs.is_open() or not ffs.is_open()) return false;

    adapter.start();
    Point3d p;
    while (adapter.request_vertex(p)){
        vfs << p.x() << " " << p.y() << " " << p.z() << std::endl;
    }
    vfs.close();

    std::vector<int> c;
    while (adapter.request_collection(c)){
        for (int i : c) {
            ffs << i << " ";
        }
        ffs << std::endl;
    }
    ffs.close();
    adapter.end();
    return true;
}
