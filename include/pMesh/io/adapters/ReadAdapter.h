/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/12
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_READADAPTER_H
#define PMESH_READADAPTER_H

#include <pMesh/Common.h>

namespace pMesh::io {
    class ReadAdapter {
    public:
        virtual void start(){};

        virtual void end(){};

        virtual void feed_vertex(const Point3d &v) = 0;

        virtual void feed_cell(const std::vector<int> &c) = 0;
    };
}

#endif //PMESH_READADAPTER_H
