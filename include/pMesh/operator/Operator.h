/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/6
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: Operator for mesh
 * ------------------------------------
**/

#ifndef PMESH_OPERATOR_H
#define PMESH_OPERATOR_H

#include <pMesh/core/Surface/Mesh.h>

namespace pMesh {
    class Operator {
    public:
        virtual Operator() {};

        virtual ~Operator() {};

    public:
        template<int VertexND, int CellND>
        virtual operator()(Mesh<VertexND, CellND> &mesh) = 0;
    };
}

#endif //PMESH_OPERATOR_H
