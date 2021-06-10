/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/13
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#include <pMesh/io/writer/OBJWriter.h>

pMesh::io::OBJWriter::OBJWriter(const pMesh::io::fs_path &path): path(path) {}

bool pMesh::io::OBJWriter::operator<<(pMesh::io::WriteAdapter &adapter) {

    return true;
}
