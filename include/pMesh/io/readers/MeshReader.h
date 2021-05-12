/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/12
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_MESHREADER_H
#define PMESH_MESHREADER_H

#include <pMesh/Common.h>
#include <pMesh/io/adapters/IOAdapter.h>
#include <boost/filesystem.hpp>

namespace pMesh::io{
    using fs_path = boost::filesystem::path;
    class MeshReader{
    public:
        virtual operator >> (IOAdapter &adapter) = 0;
    };

}

#endif //PMESH_MESHREADER_H
