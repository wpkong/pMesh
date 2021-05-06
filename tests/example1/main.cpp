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

BOOST_AUTO_TEST_SUITE(test)
    BOOST_AUTO_TEST_CASE(test_1d) {
//        using namespace pMesh;
        std::vector<int> encoded{6,2,7,3}, arr;
        int first = 4;
        arr.resize(encoded.size() + 1);
        arr[0] = first;
        for (int i = 0; i < encoded.size(); ++i) {
            arr[i + 1] = encoded[i] ^ arr[i];
            std::cout << arr[i + 1] << " | ";
        }
    }
BOOST_AUTO_TEST_SUITE_END()