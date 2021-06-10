/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/12
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_BASEREADER_H
#define PMESH_BASEREADER_H

#include <pMesh/Common.h>
#include <pMesh/io/adapter/ReadAdapter.h>
#include <boost/filesystem.hpp>

namespace pMesh::io{
    using fs_path = boost::filesystem::path;

    class BaseReader{
    public:
        virtual bool operator >> (ReadAdapter &adapter) = 0;
    };
}

#endif //PMESH_BASEREADER_H
