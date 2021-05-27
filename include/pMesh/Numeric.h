/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/27
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_NUMERIC_H
#define PMESH_NUMERIC_H

#include <pMesh/Common.h>

namespace pMesh{
    inline double approximate(const double x, const double eps) {
        return std::fabs(x - round(x)) < eps ? (round(x) == -0.0 ? 0 : round(x)) : x;
    }
}

#endif //PMESH_NUMERIC_H
