/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/6
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_CELLVERTICESORDERREGULATOR_H
#define PMESH_CELLVERTICESORDERREGULATOR_H

#include <pMesh/operators/Operator.h>

namespace pMesh{
    class CellVerticesOrderRegulator: public Operator{
    private:
        bool reverse;

    public:
        explicit CellVerticesOrderRegulator(bool reverse=false);
        ~CellVerticesOrderRegulator() override = default;

    public:
        void operator()(Triangle3dMesh &mesh);
    };

}

#include <pMesh/operators/CellVerticesOrderRegulator.impl>

#endif //PMESH_CELLVERTICESORDERREGULATOR_H
