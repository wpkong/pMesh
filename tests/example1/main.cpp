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
#include <pMesh/core/Decl.h>
#include <pMesh/core/HalfEdge.h>

BOOST_AUTO_TEST_SUITE(test)
    BOOST_AUTO_TEST_CASE(test_1d) {
        pMesh::halfedge_sptr<3,3> prt(new pMesh::HalfEdge<3,3>);
    }
BOOST_AUTO_TEST_SUITE_END()