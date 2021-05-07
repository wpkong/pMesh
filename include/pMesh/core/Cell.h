/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/7
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_CELL_H
#define PMESH_CELL_H

#include <pMesh/Common.h>
#include <pMesh/core/Null.h>

namespace pMesh{
    template<int CellND, class Trait=Null::NullTrait>
    class Cell{
        using Cell_Vertex_T = std::array<size_t, CellND>;
    public:
        Cell_Vertex_T vertices;
        Trait trait;
    };
}

#endif //PMESH_CELL_H
