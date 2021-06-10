/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/4/28
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_TRIANGLEMESH_H
#define PMESH_TRIANGLEMESH_H

#include <pMesh/core/SurfaceMesh.h>
#include <vector>

namespace pMesh{
    template<class VertexExtraData=Surface::BaseVertexExtraData,
            class HalfEdgeExtraData=Surface::BaseHalfEdgeExtraData,
            class EdgeExtraData = Surface::BaseEdgeExtraData,
            class FaceExtraData = Surface::BaseFaceExtraData>
    class Triangle3dMesh: public SurfaceMesh<VertexExtraData, HalfEdgeExtraData, EdgeExtraData, FaceExtraData>{

    };
}

#endif //PMESH_TRIANGLEMESH_H
