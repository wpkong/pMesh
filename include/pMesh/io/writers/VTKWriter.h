/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/13
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_VTKWRITER_H
#define PMESH_VTKWRITER_H

#include <pMesh/io/writers/BaseWriter.h>


namespace pMesh::io{
    class VTKWriter: public BaseWriter{
        const double eps = 1e-9;
    private:
        const fs_path path;
        const int type;
    public:
        explicit VTKWriter(int type, const fs_path &path);

        bool operator << (WriteAdapter &adapter) override;
    };
}


#endif //PMESH_VTKWRITER_H
