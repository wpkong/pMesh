/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/7
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_VOLUMEMESH_H
#define PMESH_VOLUMEMESH_H

namespace pMesh{
    template<int CellND>
    class VolumeMesh: public Mesh<3, CellND>{

    };
}

#endif //PMESH_VOLUMEMESH_H
