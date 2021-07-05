/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/26
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_TETRAHEDRONMESH_H
#define PMESH_TETRAHEDRONMESH_H
#include <pMesh/core/VolumeMesh.h>
#include <pMesh/mesh/TriangleMesh.h>

namespace pMesh{
    template<class VertexExtraData=Volume::BaseVertexExtraData,
            class HalfEdgeExtraData=Volume::BaseHalfEdgeExtraData,
            class EdgeExtraData = Volume::BaseEdgeExtraData,
            class HalfFaceExtraData = Volume::BaseHalfFaceExtraData,
            class FaceExtraData = Volume::BaseFaceExtraData,
            class CellExtraData = Volume::BaseCellExtraData
    >
    class TetrahedronMesh: public VolumeMesh<VertexExtraData, HalfEdgeExtraData, EdgeExtraData, HalfFaceExtraData, FaceExtraData, CellExtraData>{
    public:
        void build_half_face_structure(){}
    };
}

#endif //PMESH_TETRAHEDRONMESH_H
