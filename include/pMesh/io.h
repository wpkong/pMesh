/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/6
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_IO_H
#define PMESH_IO_H

#include <pMesh/Mesh.h>
#include <pMesh/3d/TriangleMesh.h>
#include <boost/filesystem.hpp>

namespace pMesh{
    typedef boost::filesystem::path fs_path;
}

/**
 * Read
 */
namespace pMesh::io {
    bool read_obj(Triangle3dMesh &mesh, const fs_path &path);

    bool read_stl(Triangle3dMesh &mesh, const fs_path &path);

    bool read_off(Triangle3dMesh &mesh, const fs_path &path);
};

/**
 * Write
 */
namespace pMesh::io{
    bool write_obj(Triangle3dMesh &mesh, const fs_path &path);

    bool write_stl(Triangle3dMesh &mesh, const fs_path &path);

    bool write_off(Triangle3dMesh &mesh, const fs_path &path);
}


#endif //PMESH_IO_H
