/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/22
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#include <pMesh/functional/MarchingCubes/MarchingCubes.h>

namespace pMesh {
    Vector3d default_grad(const signed_directional_field &f, const Point3d &p, double eps = 1e-6) {
        const Vector3d delta[3]{{eps, 0,   0},
                                {0,   eps, 0},
                                {0,   0,   eps}};
        double grad[3];
        for (int i = 0; i < 3; ++i) {
            grad[i] = (f(p + delta[i]) - f(p - delta[i])) / 2;
        }
        return {grad[0], grad[1], grad[2]};
    }

    void triangulate(){

    }
}



pMesh::Triangle3dMesh<> pMesh::isosurface(
        signed_directional_field sdf, const Domain3d &domain, const Vector3d &size,
        double level, grad_func grad, bool compact_points) {
    pMesh::Triangle3dMesh<> mesh;
    if(grad == nullptr){
        grad = [sdf](auto && PH1) { return default_grad(sdf, std::forward<decltype(PH1)>(PH1), 1e-6); };
    }
    const int num_x = (int)std::ceil(std::abs(domain.get<0>().first - domain.get<0>().second) / size.x());
    const int num_y = (int)std::ceil(std::abs(domain.get<1>().first - domain.get<1>().second) / size.y());
    const int num_z = (int)std::ceil(std::abs(domain.get<2>().first - domain.get<2>().second) / size.z());
    const Vector3d center_offset = size / 2;


    for (int i = 0; i < num_x; ++i) {
        double x = domain.get<0>().first + i * size.x();
        for (int j = 0; j < num_y; ++j) {
            double y = domain.get<1>().first + j * size.y();
            for (int k = 0; k < num_z; ++k) {
                double z = domain.get<2>().first + k * size.z();

                Point3d p(x,y,z);
                Point3d center = p + center_offset;
            }
        }
    }
}