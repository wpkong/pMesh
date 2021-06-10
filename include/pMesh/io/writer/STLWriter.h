/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/13
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_OBJWRITER_H
#define PMESH_OBJWRITER_H

#include <pMesh/io/writer/BaseWriter.h>


namespace pMesh::io{
    class STLWriter: public BaseWriter{
    private:
        const fs_path path;
    public:
        explicit STLWriter(const fs_path &path);

        bool operator << (WriteAdapter &adapter) override;
    };
}


#endif //PMESH_OBJWRITER_H
