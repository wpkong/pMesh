/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/4/28
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_FRAME_H
#define PMESH_FRAME_H

#include <pMesh/Common.h>

namespace pMesh{
    class Frame{
        Vector3d normal;
        Vector3d binormal;
        Vector3d direction;
    };
}

#endif //PMESH_FRAME_H
