/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/13
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_BASEWRITER_H
#define PMESH_BASEWRITER_H

#include <pMesh/Common.h>
#include <pMesh/io/adapter/WriteAdapter.h>
#include <boost/filesystem.hpp>

namespace pMesh::io{
    using fs_path = boost::filesystem::path;

    class BaseWriter{
    public:
        virtual bool operator << (WriteAdapter &adapter) = 0;
    };
}


#endif //PMESH_BASEWRITER_H
