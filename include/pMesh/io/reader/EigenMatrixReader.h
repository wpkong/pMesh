/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/7/5
 * @email: yjxkwp@foxmail.com
 * @site: https://donot.fit
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_EIGENMATRIXREADER_H
#define PMESH_EIGENMATRIXREADER_H

#include <pMesh/io/reader/BaseReader.h>

namespace pMesh::io{
    class EigenMatrixReader: public pMesh::io::BaseReader{
        const Eigen::MatrixXd &V;
        const Eigen::MatrixXi &C;
    public:
        EigenMatrixReader(const Eigen::MatrixXd &V, const Eigen::MatrixXi &C);

        bool operator >> (pMesh::io::ReadAdapter &adapter) override;
    };
}

#endif //PMESH_EIGENMATRIXREADER_H
