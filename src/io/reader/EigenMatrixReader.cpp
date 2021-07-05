/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/7/5
 * @email: yjxkwp@foxmail.com
 * @site: https://donot.fit
 * @description: 
 * ------------------------------------
**/

#include "pMesh/io/reader/EigenMatrixReader.h"
#include <boost/log/trivial.hpp>
#include <boost/assert.hpp>

pMesh::io::EigenMatrixReader::EigenMatrixReader(const Eigen::MatrixXd &V, const Eigen::MatrixXi &C) : V(V), C(C) {
    BOOST_ASSERT_MSG(V.cols() == 3, "Size of V must be size n * 3");
}

bool pMesh::io::EigenMatrixReader::operator>>(pMesh::io::ReadAdapter &adapter) {
    adapter.start();
    const size_t v_n = V.rows();
    const size_t c_n = C.rows();

    for (int i = 0; i < v_n; ++i) {
        adapter.feed_vertex(V.row(i).transpose());
    }

    for (int i = 0; i < c_n; ++i) {
        const auto &collection = C.row(i);
        std::vector<int> c_vec(collection.size());
        for (int j = 0; j < collection.size(); ++j) {
            c_vec[j] = collection[j];
        }
        adapter.feed_collection(c_vec);
    }
    adapter.end();
    return true;
}

