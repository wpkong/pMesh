/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/6/17
 * @email: yjxkwp@foxmail.com
 * @site: https://donot.fit
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_BOUNDINGSPHERE_H
#define PMESH_BOUNDINGSPHERE_H

#include <pMesh/Common.h>
#include <pMesh/core/Mesh.h>

#include <boost/tuple/tuple.hpp>
#include <boost/log/trivial.hpp>

namespace pMesh {
    template<class VertexField>
    boost::tuple<Point3d, double> bounding_sphere(const BasePointCloudMesh<VertexField> &pcm,
                                                  int num_iterations = 100,
                                                  const float factor = 0.95);
}

// ------------------------------ implementation ------------------------------
template<class VertexField>
boost::tuple<pMesh::Point3d, double> pMesh::bounding_sphere(const BasePointCloudMesh<VertexField> &pcm,
                                                            int num_iterations,
                                                            const float factor) {
    Point3d center(0, 0, 0);
    Point3d best_center(0, 0, 0);
    Point3d rv(0, 0, 0);

    size_t v_size = pcm.vertices.size();
    if (pcm.vertices.empty()) {
        BOOST_LOG_TRIVIAL(error) << "Vertices list can not be empty.";
        return boost::make_tuple(center, 0);
    }

    std::vector<int> min_id(3, 0), max_id(3, 0);

    std::vector<Point3d> permutation(v_size);

    for (int i = 0; i < v_size; ++i) {
        permutation[i] = pcm.vertices[i].attr.coordinate;
        const auto &vertex = permutation[i];
        for (unsigned j = 0; j < 3; ++j) {
            if (vertex[j] < permutation[min_id[j]][j])
                min_id[j] = i;
            if (vertex[j] > permutation[max_id[j]][j])
                max_id[j] = i;
        }
    }

    unsigned support = 0;
    double support_dsq = 0.0f;
    for (unsigned i = 0; i < 3; ++i) {
        double dsq = 0.0f;
        for (unsigned j = 0; j < 3; ++j) {
            double d = permutation[max_id[i]][j] - permutation[min_id[i]][j];
            dsq += d * d;
        }
        if (dsq > support_dsq) {
            support = i;
            support_dsq = dsq;
        }
    }

    double radius = 0.0f, best_radius = std::numeric_limits<double>::max();
    for (unsigned i = 0; i < 3; ++i) {
        center[i] = 0.5f * (permutation[min_id[support]][i] + permutation[max_id[support]][i]);
        double d = center[i] - permutation[min_id[support]][i];
        radius += d * d;
    }
    double rr = std::sqrt(radius);
    if (rr != 0.0f)
        radius /= rr;


    do {
        double radius_squared = radius * radius;
        for (unsigned i = 0; i < v_size; ++i) {
            unsigned j = rand() % (v_size - i);
            std::swap(permutation[i + j], permutation[i]);
            const auto &other = permutation[i];

            double dsq = 0.0f;
            for (unsigned j = 0; j < 3; ++j) {
                rv[j] = other[j] - center[j];
                dsq += rv[j] * rv[j];
            }

            if (dsq > radius_squared) {
                double distance = std::sqrt(dsq);
                double new_radius = (radius + distance) * 0.5f;
                double radius_delta = new_radius - radius;
                radius = new_radius;
                radius_squared = new_radius * new_radius;
                double s = radius_delta / distance;
                for (unsigned j = 0; j < 3; ++j)
                    center[j] += rv[j] * s;
            }
        }

        if (radius < best_radius) {
            for (unsigned i = 0; i < 3; ++i)
                best_center[i] = center[i];
            best_radius = radius;
        }

        radius *= factor;
    } while (num_iterations--);

    return boost::make_tuple(best_center, best_radius);
}

#endif //PMESH_BOUNDINGSPHERE_H
