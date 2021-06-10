/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/12
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_VTKREADER_H
#define PMESH_VTKREADER_H

#include <pMesh/io/reader/BaseReader.h>

namespace pMesh::io {
    class VTKReader: public BaseReader{
        const fs_path path;
    public:
        explicit VTKReader(const fs_path &path);

    public:
        bool operator >> (ReadAdapter &adapter) override;
    };
}

#endif //PMESH_VTKREADER_H
