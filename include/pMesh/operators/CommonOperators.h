/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/5
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_COMMONOPERATORS_H
#define PMESH_COMMONOPERATORS_H

#include <pMesh/Common.h>
#include <pMesh/Mesh.h>
#include <pMesh/3d/TriangleMesh.h>

namespace pMesh::Operator{
    /**
     *
     * @tparam VertexND Vertex point dimension
     * @tparam CellND Cell dimension
     * @param mesh
     */
    template<int VertexND, int CellND>
    void eliminate_redundant_vertices(Mesh<VertexND, CellND> &mesh);

    /**
     * Make triangle vertex order regulated.
     * @param mesh
     */
    void regulate_cell_vertex_order(Triangle3dMesh &mesh, bool reverse=false);
};

// Implementations
#include <pMesh/operators/CommonOperators.impl>


#endif //PMESH_COMMONOPERATORS_H
