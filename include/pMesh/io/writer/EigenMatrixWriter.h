/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/7/5
 * @email: yjxkwp@foxmail.com
 * @site: https://donot.fit
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_EIGENMATRIXWRITER_H
#define PMESH_EIGENMATRIXWRITER_H

#include <pMesh/io/writer/BaseWriter.h>

namespace pMesh::io{
    class EigenMatrixWriter: public BaseWriter{
    private:
        Eigen::MatrixXd &V;
        Eigen::MatrixXi &C;
        const size_t collection_size;

    public:
        explicit EigenMatrixWriter(Eigen::MatrixXd &V, Eigen::MatrixXi &C, size_t collection_size);

        bool operator << (WriteAdapter &adapter) override;
    };
}


#endif //PMESH_EIGENMATRIXWRITER_H
