/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/26
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_HEXAHEDRONMESH_H
#define PMESH_HEXAHEDRONMESH_H

#include <pMesh/core/VolumeMesh.h>

namespace pMesh{
    template<class VertexExtraData=Volume::BaseVertexExtraData,
            class HalfEdgeExtraData=Volume::BaseHalfEdgeExtraData,
            class EdgeExtraData = Volume::BaseEdgeExtraData,
            class HalfFaceExtraData = Volume::BaseHalfFaceExtraData,
            class FaceExtraData = Volume::BaseFaceExtraData,
            class CellExtraData = Volume::BaseCellExtraData
    >
    class HexahedronMesh: public VolumeMesh<VertexExtraData, HalfEdgeExtraData, EdgeExtraData, HalfFaceExtraData, FaceExtraData, CellExtraData>{

        void build_half_face_structure();
    };

}

#include <pMesh/mesh/HexahedronMesh_impl.h>

#endif //PMESH_HEXAHEDRONMESH_H
