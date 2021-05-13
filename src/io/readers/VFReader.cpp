/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/13
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#include <pMesh/io/readers/VFReader.h>
#include <fstream>
#include <sstream>

pMesh::io::VFReader::VFReader(const pMesh::io::fs_path &v_path, const pMesh::io::fs_path &f_path):
v_path(v_path), f_path(f_path) {

}

bool pMesh::io::VFReader::operator>>(pMesh::io::ReadAdapter &adapter) {
    std::fstream vfs(this->v_path.c_str());
    std::fstream ffs(this->f_path.c_str());
    if(not vfs.is_open() or not ffs.is_open()) return false;

    adapter.start();
    std::string line;
    while (std::getline(vfs, line)){
        std::stringstream ss(line);
        Point3d p;
        ss >> p.x() >> p.y() >> p.z();
        adapter.feed_vertex(p);
    }

    while (std::getline(ffs, line)){
        std::stringstream ss(line);
        double v;
        std::vector<int> c;
        while (ss >> v){
            c.push_back((int)v);
        }
        adapter.feed_cell(c);
    }
    adapter.end();
    return true;
}
