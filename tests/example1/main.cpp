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
#include <pMesh/core/Surface/Mesh.h>
#include <pMesh/core/ExtraData.h>
#include <pMesh/io/readers/STLReader.h>
#include <pMesh/io/adapters/DefaultReadAdapter.h>

BOOST_AUTO_TEST_SUITE(test)

    BOOST_AUTO_TEST_CASE(test_1d) {
        pMesh::Mesh m;
        pMesh::io::STLReader("/Users/kwp/Projects/Porous/models/insole/model.stl") >>
                                                                                   pMesh::io::DefaultReadAdapter(m)();
        BOOST_LOG_TRIVIAL(debug) << "Loaded points: " << m.v_size();
        BOOST_LOG_TRIVIAL(debug) << "Loaded cells: " << m.c_size();
    }

BOOST_AUTO_TEST_SUITE_END()