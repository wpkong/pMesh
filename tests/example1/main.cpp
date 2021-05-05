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
#include <pMesh/Mesh.h>
#include <pMesh/operators/CommonOperators.h>


BOOST_AUTO_TEST_SUITE(test)
    BOOST_AUTO_TEST_CASE(test_1d) {
        using namespace pMesh;
        Mesh<3,3> mesh;
        Operator::eliminate_redundant_vertices(mesh);
    }
BOOST_AUTO_TEST_SUITE_END()