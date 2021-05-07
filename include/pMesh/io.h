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

#include <pMesh/core/Mesh.h>
#include <pMesh/meshes/TriangleMesh.h>
#include <boost/filesystem.hpp>

namespace pMesh{
    typedef boost::filesystem::path fs_path;
}

/**
 * Read
 */
namespace pMesh::io {
    template<class HalfEdgeTrait, class VertexTrait, class CellTrait>
    bool read_obj(Triangle3dMesh<HalfEdgeTrait, VertexTrait, CellTrait> &mesh, const fs_path &path);

    template<class HalfEdgeTrait, class VertexTrait, class CellTrait>
    bool read_stl(Triangle3dMesh<HalfEdgeTrait, VertexTrait, CellTrait> &mesh, const fs_path &path);

    template<class HalfEdgeTrait, class VertexTrait, class CellTrait>
    bool read_off(Triangle3dMesh<HalfEdgeTrait, VertexTrait, CellTrait> &mesh, const fs_path &path);
};

/**
 * Write
 */
namespace pMesh::io{
    template<class HalfEdgeTrait, class VertexTrait, class CellTrait>
    bool write_obj(Triangle3dMesh<HalfEdgeTrait, VertexTrait, CellTrait> &mesh, const fs_path &path);

    template<class HalfEdgeTrait, class VertexTrait, class CellTrait>
    bool write_stl(Triangle3dMesh<HalfEdgeTrait, VertexTrait, CellTrait> &mesh, const fs_path &path);

    template<class HalfEdgeTrait, class VertexTrait, class CellTrait>
    bool write_off(Triangle3dMesh<HalfEdgeTrait, VertexTrait, CellTrait> &mesh, const fs_path &path);
}


#endif //PMESH_IO_H
