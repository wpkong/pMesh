/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/13
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_VFWRITER_H
#define PMESH_VFWRITER_H

#include <pMesh/io/writer/BaseWriter.h>


namespace pMesh::io{
    class VFWriter: public BaseWriter{
    protected:
        const fs_path v_path;
        const fs_path f_path;
        std::ofstream vfs;
        std::ofstream ffs;

    public:
        explicit VFWriter(const fs_path &v_path, const fs_path &f_path);

        bool operator << (WriteAdapter &adapter) override;
    };
}


#endif //PMESH_VFWRITER_H
