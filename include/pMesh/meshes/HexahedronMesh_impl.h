/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/26
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_HEXAHEDRONMESH_IMPL_H
#define PMESH_HEXAHEDRONMESH_IMPL_H

#include <pMesh/meshes/HexahedronMesh.h>


template<class VertexExtraData,
        class HalfEdgeExtraData,
        class EdgeExtraData,
        class HalfFaceExtraData,
        class FaceExtraData,
        class CellExtraData>
void pMesh::HexahedronMesh<VertexExtraData, HalfEdgeExtraData, EdgeExtraData, HalfFaceExtraData, FaceExtraData, CellExtraData>::
build_half_face_structure() {

}

#endif //PMESH_HEXAHEDRONMESH_IMPL_H
