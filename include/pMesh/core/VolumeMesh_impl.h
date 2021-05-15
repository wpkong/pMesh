/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/15
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_VOLUMEMESH_IMPL_H
#define PMESH_VOLUMEMESH_IMPL_H

#include <pMesh/Common.h>
#include <pMesh/core/VolumeMesh.h>
#include <map>


template<class VertexExtraData, class HalfEdgeExtraData, class EdgeExtraData, class HalfFaceExtraData, class FaceExtraData, class CellExtraData>
void
pMesh::VolumeMesh<VertexExtraData, HalfEdgeExtraData, EdgeExtraData, HalfFaceExtraData, FaceExtraData, CellExtraData>::clear_half_face_structure() {
    this->half_edges.clear();
    this->edges.clear();
    this->half_faces.clear();
    this->faces.clear();
    this->cells.clear();
}



#endif //PMESH_VOLUMEMESH_IMPL_H
