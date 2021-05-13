/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/13
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_WRITEADAPTER_H
#define PMESH_WRITEADAPTER_H

#include <pMesh/Common.h>

namespace pMesh::io{
    class WriteAdapter{
    public:
        virtual void start() {}

        virtual size_t request_number_of_vertices() = 0;

        virtual size_t request_number_of_cells() = 0;

        virtual bool request_vertex(Point3d &p) = 0;

        virtual bool request_cell(std::vector<int> &c) = 0;

        virtual void end() {}

        WriteAdapter &base() {
            return *this;
        }

        WriteAdapter &operator()() {
            return *this;
        }
    };
}

#endif //PMESH_WRITEADAPTER_H
