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

#include <pMesh/io/writers/BaseWriter.h>


namespace pMesh::io{
    class OBJWriter: public BaseWriter{
    private:
        const fs_path path;
    public:
        explicit OBJWriter(const fs_path &path);

        bool operator << (WriteAdapter &adapter) override;
    };
}


#endif //PMESH_OBJWRITER_H
