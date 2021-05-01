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

#include <pMesh/Mesh.h>
#include <vector>

namespace pMesh{
    class Triangle3dMesh: public Mesh<Point3d, TriangleCell>{
    public:
        std::vector<Vector3d> cell_normals;


    public:
        /**
         * Calculate triangle cell normals
         */
        void calculate_cell_normals();

        /**
         * Regulate triangle normals
         */
        void regulate(bool reverse=false);
    };
}

#endif //PMESH_TRIANGLEMESH_H
