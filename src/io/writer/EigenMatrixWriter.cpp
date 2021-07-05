/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/7/5
 * @email: yjxkwp@foxmail.com
 * @site: https://donot.fit
 * @description: 
 * ------------------------------------
**/

#include "pMesh/io/writer/EigenMatrixWriter.h"

pMesh::io::EigenMatrixWriter::EigenMatrixWriter(Eigen::MatrixXd &V, Eigen::MatrixXi &C, size_t collection_size) :
        V(V), C(C), collection_size(collection_size) {

}

bool pMesh::io::EigenMatrixWriter::operator<<(pMesh::io::WriteAdapter &adapter) {
    int cnt = 0;

    adapter.start();

    V.resize(adapter.request_number_of_vertices(), 3);
    C.resize(adapter.request_number_of_collections(), collection_size);

    Point3d p;
    cnt = 0;
    while (adapter.request_vertex(p)) {
        V.row(cnt) << p.x(), p.y(), p.z();
        cnt++;
    }

    std::vector<int> c;
    cnt = 0;
    while (adapter.request_collection(c)) {
        BOOST_ASSERT_MSG(c.size() == collection_size, "collection_size is not compatible with cells size.");
        for (int i = 0; i < collection_size; ++i) {
            C(cnt, i) = c[i];
        }
        cnt++;
    }
    adapter.end();
    return true;
}
