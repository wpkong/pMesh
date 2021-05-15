/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/15
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_CELL_H
#define PMESH_CELL_H

#include <pMesh/Common.h>
#include <pMesh/core/Handle.h>

namespace pMesh {
    class BaseCell {
    };
}

namespace pMesh::Volume {
    class Cell : public BaseCell {
    public:
        int id = -1;

    public:
        std::vector<VertexHandle> vertices;

    public:
        std::vector<HalfFaceHandle> half_edges;
    };
}

#endif //PMESH_CELL_H
