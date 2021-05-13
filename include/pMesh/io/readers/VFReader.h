/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/13
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_VFREADER_H
#define PMESH_VFREADER_H


#include <pMesh/io/readers/BaseReader.h>

namespace pMesh::io {
    class VFReader: public BaseReader{
        const fs_path v_path;
        const fs_path f_path;
    public:
        explicit VFReader(const fs_path &v_path, const fs_path &f_path);

    public:
        bool operator >> (ReadAdapter &adapter) override;
    };
}


#endif //PMESH_VFREADER_H
