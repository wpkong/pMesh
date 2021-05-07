/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/6
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_REDUNDANTVERTICESELIMINATER_H
#define PMESH_REDUNDANTVERTICESELIMINATER_H

#include <pMesh/operators/Operator.h>

namespace pMesh{
    class RedundantVerticesEliminater: public Operator{
    public:
        RedundantVerticesEliminater() = default;
        ~RedundantVerticesEliminater() = default;

    public:
        template<int VertexND, int CellND>
        void operator()(Mesh<VertexND, CellND> &mesh) override;
    };
}

#include <pMesh/operators/RedundantVerticesEliminater_impl.h>

#endif //PMESH_REDUNDANTVERTICESELIMINATER_H
