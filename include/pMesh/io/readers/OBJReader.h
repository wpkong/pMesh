/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/12
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_OBJREADER_H
#define PMESH_OBJREADER_H

#include <pMesh/io/readers/MeshReader.h>

namespace pMesh::io {
    class OBJReader: public MeshReader{
        const fs_path path;
    public:
        explicit OBJReader(const fs_path &path);

    public:
        void operator >> (IOAdapter &adapter);
    };
}

#endif //PMESH_OBJREADER_H
