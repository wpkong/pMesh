/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/4/28
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>
#include <boost/log/trivial.hpp>
#include <pMesh/core/SurfaceMesh.h>
#include <pMesh/core/ExtraData.h>
#include <pMesh/io/readers/STLReader.h>
#include <pMesh/io/adapters/DefaultReadAdapter.h>

BOOST_AUTO_TEST_SUITE(test)

    BOOST_AUTO_TEST_CASE(test_1d) {
        pMesh::SurfaceMesh m;
        pMesh::io::STLReader("/Users/kwp/Projects/Porous/models/insole/model.stl") >>
                                                                                   pMesh::io::DefaultSurfaceReadAdapter(m)();
        BOOST_LOG_TRIVIAL(debug) << "Loaded points: " << m.v_size();
        BOOST_LOG_TRIVIAL(debug) << "Loaded faces: " << m.f_size();
        auto aabb = m.aabb();
        BOOST_LOG_TRIVIAL(debug) << "AABB(x): " << aabb[0] << " x " << aabb[1];
        BOOST_LOG_TRIVIAL(debug) << "AABB(y): " << aabb[2] << " x " << aabb[3];
        BOOST_LOG_TRIVIAL(debug) << "AABB(z): " << aabb[4] << " x " << aabb[5];
    }

BOOST_AUTO_TEST_SUITE_END()