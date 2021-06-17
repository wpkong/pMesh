/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/6/17
 * @email: yjxkwp@foxmail.com
 * @site: https://donot.fit
 * @description: 
 * ------------------------------------
**/

#include <pMesh/functional/BoundingSphere.h>
#include <pMesh/core/SurfaceMesh.h>

int main(){
    pMesh::SurfaceMesh model;
    model.vertices.emplace_back(pMesh::Surface::Vertex(0, {0,0,0}));
    model.vertices.emplace_back(pMesh::Surface::Vertex(1, {1,0,0}));
    model.vertices.emplace_back(pMesh::Surface::Vertex(2, {1,1,0}));
    model.vertices.emplace_back(pMesh::Surface::Vertex(3, {0,1,0}));
    model.vertices.emplace_back(pMesh::Surface::Vertex(4, {0,0,1}));
    model.vertices.emplace_back(pMesh::Surface::Vertex(5, {1,0,1}));
    model.vertices.emplace_back(pMesh::Surface::Vertex(6, {1,1,1}));
    model.vertices.emplace_back(pMesh::Surface::Vertex(7, {0,1,1}));

    model.move({-.5, -.5, -.5});

    auto [center, r] = pMesh::bounding_sphere(model);

    BOOST_LOG_TRIVIAL(info) << "Center: " << center.transpose();
    BOOST_LOG_TRIVIAL(info) << "Radius: " << r;

    return 0;
}