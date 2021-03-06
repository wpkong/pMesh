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

#include <pMesh/operator/Operator.h>
#include <pMesh/3d/TriangleMesh.h>

namespace pMesh{
    class CellVerticesOrderRegulator: public Operator{
    private:
        bool reverse;

    public:
        explicit CellVerticesOrderRegulator(bool reverse=false);
        ~CellVerticesOrderRegulator() override = default;

    public:
        template<class HalfEdgeTrait,
                class VertexTrait,
                class CellTrait>
        void operator()(Triangle3dMesh<HalfEdgeTrait, VertexTrait, CellTrait> &mesh) override;
    };

}

#include <pMesh/operators/CellVerticesOrderRegulator_impl.h>

#endif //PMESH_CELLVERTICESORDERREGULATOR_H
