/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/15
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_SURFACEMESH_IMPL_H
#define PMESH_SURFACEMESH_IMPL_H


#include <pMesh/Common.h>
#include <pMesh/core/SurfaceMesh.h>
#include <queue>
#include <boost/assert.hpp>
#include <boost/log/trivial.hpp>
#include <boost/progress.hpp>
#include <map>

template<class VertexExtraData, class HalfEdgeExtraData, class EdgeExtraData, class FaceExtraData>
void pMesh::SurfaceMesh<VertexExtraData, HalfEdgeExtraData, EdgeExtraData, FaceExtraData>::clear_half_edge_structure() {
    this->half_edges.clear();
    this->edges.clear();

    for (size_t i = 0; i < this->vertices.size(); ++i) {
        auto &vertex = this->vertices[i];
        vertex.attr.id = i;
        vertex.attr.half_edge_in.clear();
        vertex.attr.half_edge_out.clear();
    }

    for (size_t i = 0; i < this->faces.size(); ++i) {
        auto &face = this->faces[i];
        face.attr.half_edges.clear();
        face.attr.id = i;
    }
}


template<class VertexExtraData,
        class HalfEdgeExtraData,
        class EdgeExtraData,
        class FaceExtraData>
void pMesh::SurfaceMesh<VertexExtraData, HalfEdgeExtraData, EdgeExtraData, FaceExtraData>::
build_half_edge_structure() {
    this->clear_half_edge_structure();

    std::map<std::pair<int, int>, int> edge_map;  // <min, max>, idx

    for (size_t i = 0; i < this->faces.size(); ++i) {
        auto &face = this->faces[i];
        face.attr.half_edges.clear();
        face.attr.id = i;
        for (int j = 0; j < face.attr.vertices.size(); ++j) {
            int a = face.attr.vertices[j].id();
            int b = face.attr.vertices[(j + 1) % face.attr.vertices.size()].id();

            HalfEdge he;
            he.id = this->half_edges.size();
            he.face = face.attr.id;
            he.vertex_start = a;
            he.vertex_end = b;

            std::pair<int, int> edge_pair(std::min(a, b), std::max(a, b));
            auto edge_fd = edge_map.find(edge_pair);
            Edge *e_ptr;
            if(edge_fd == edge_map.end()){
                Edge e;
                e.va = edge_pair.first;
                e.vb = edge_pair.second;
                e.id = this->edges.size();
                // update
                this->edges.emplace_back(e);
                edge_map[edge_pair] = e.id;
                e_ptr = &(this->edges.back().attr);
                e_ptr->half_edge_pair.first = he.id;

            }else{
                e_ptr = &(this->edges[edge_fd->second].attr);
                BOOST_ASSERT_MSG(e_ptr->half_edge_pair.second.id() == -1,
                                 "Invalid mesh: more than 2 half edges share one edge.");
                e_ptr->half_edge_pair.second = he.id;
            }
            he.edge = e_ptr->id;
            vertex(VertexHandle{a}).half_edge_out.emplace_back(he.id);
            vertex(VertexHandle{b}).half_edge_in.emplace_back(he.id);
            face.attr.half_edges.emplace_back(he.id);
            // update
            this->half_edges.emplace_back(he);
        }

        int he_n = face.attr.half_edges.size();
        for (int i = 0; i < he_n; ++i){
            auto he = face.attr.half_edges[i];
            auto prev_i = face.attr.half_edges[(i + he_n - 1) % he_n];
            auto next_i = face.attr.half_edges[(i + he_n + 1) % he_n];
            half_edge(he).prev = half_edge(prev_i).id;
            half_edge(he).next = half_edge(next_i).id;
        }
    }
    this->half_edge_dirty = false;
}

template<class VertexExtraData, class HalfEdgeExtraData, class EdgeExtraData, class FaceExtraData>
void pMesh::SurfaceMesh<VertexExtraData, HalfEdgeExtraData, EdgeExtraData, FaceExtraData>::compact_vertices() {
    auto old_vertices = this->vertices;
    auto old_faces = this->faces;
    this->vertices.clear();
    this->faces.clear();

    std::map<int, int> mp;
    int fcnt = 0;
    int vcnt = 0;
    for (FaceField &face: old_faces) {
        std::vector<VertexHandle> new_geo;
        for (VertexHandle &p: face.attr.vertices) {
            if (mp.count(p.id()) == 0) {
                mp[p.id()] = this->vertices.size();
                VertexField new_v = old_vertices[p.id()];
                new_v.attr.id = vcnt++;
                this->vertices.push_back(new_v);
            }
            new_geo.emplace_back(mp[p.id()]);
        }
        face.attr.vertices = new_geo;
        face.attr.id = fcnt++;
        this->faces.push_back(face);
    }
    this->clear_half_edge_structure();
    this->half_edge_dirty = true;
    BOOST_LOG_TRIVIAL(info) << "Compacting from " << old_vertices.size() << " to " << this->vertices.size();
}

template<class VertexExtraData, class HalfEdgeExtraData, class EdgeExtraData, class FaceExtraData>
std::vector<typename pMesh::SurfaceMesh<VertexExtraData, HalfEdgeExtraData, EdgeExtraData, FaceExtraData>::MeshType>
        pMesh::SurfaceMesh<VertexExtraData, HalfEdgeExtraData, EdgeExtraData, FaceExtraData>::split_into_meshes() {
    BOOST_ASSERT_MSG(not this->half_edge_dirty, "Half-edge data structure was broken.");
    std::vector<bool> visited(this->f_size(), false);
    std::vector<MeshType> meshes;

    boost::progress_display progress(this->f_size());

    auto mark_visited = [&](int fid){
        visited[fid] = true;
        ++progress;
    };

    auto bfs = [&](MeshType &mesh, int start_fid){
        std::queue<int> q;
        q.push(start_fid);
        while (not q.empty()){
            int fid = q.front();
            q.pop();
            if(visited[fid]) continue;
            mark_visited(fid);

            const FaceField &face = this->faces[fid];
            mesh.faces.push_back(face);
            // next
            for(const VertexHandle &vh: face.attr.vertices){
                const Vertex & v= this->vertex(vh);
                for(const HalfEdgeHandle &heh: v.half_edge_in){
                    const HalfEdge he1 = this->half_edge(heh);
                    if(not visited[he1.face.id()]){
                        q.push(he1.face.id());
                    }
                }
                for(const HalfEdgeHandle &heh: v.half_edge_out){
                    const HalfEdge he1 = this->half_edge(heh);
                    if(not visited[he1.face.id()]){
                        q.push(he1.face.id());
                    }
                }
            }
//            for(const HalfEdgeHandle &eh: face.attr.half_edges){
//                const HalfEdgeHandle &twin = this->half_edge(eh).twin;
//                if(twin.is_valid()){
//                    const HalfEdge &hef = this->half_edge(twin);
//                    FaceHandle next_f = hef.face;
//                    if(next_f.is_valid() && not visited[next_f.id()]){
//                        q.push(next_f.id());
//                    }
//                }
//            }
        }
    };

    for (int fid = 0; fid < this->f_size(); ++fid){
        if(visited[fid]) continue;
        MeshType mesh;
        mesh.vertices = this->vertices;
        bfs(mesh, fid);
//        mesh.compact_vertices();
        meshes.push_back(mesh);
    }

    for(MeshType &mesh: meshes){
        mesh.clear_half_edge_structure();
        mesh.compact_vertices();
    }
    return meshes;
}

template<class VertexExtraData, class HalfEdgeExtraData, class EdgeExtraData, class FaceExtraData>
typename pMesh::SurfaceMesh<VertexExtraData, HalfEdgeExtraData, EdgeExtraData, FaceExtraData>::MeshType &
pMesh::SurfaceMesh<VertexExtraData, HalfEdgeExtraData, EdgeExtraData, FaceExtraData>::operator+=(
        pMesh::SurfaceMesh<VertexExtraData, HalfEdgeExtraData, EdgeExtraData, FaceExtraData>::MeshType mesh) {
    this->half_edge_dirty = true;
    int base_vn = this->v_size();
    int base_fn = this->f_size();
    for(VertexField &vf: mesh.vertices){
        vf.attr.id += base_vn;
        this->vertices.push_back(vf);
    }
    for(FaceField &ff: mesh.faces){
        ff.attr.id += base_fn;
        for(VertexHandle &vh: ff.attr.vertices){
            vh.index += base_vn;
        }
        this->faces.push_back(ff);
    }
    return *this;
}

template<class VertexExtraData, class HalfEdgeExtraData, class EdgeExtraData, class FaceExtraData>
void pMesh::SurfaceMesh<VertexExtraData, HalfEdgeExtraData, EdgeExtraData, FaceExtraData>::clear() {
    this->faces.clear();
    this->vertices.clear();
    this->half_edges.clear();
    this->edges.clear();
    this->half_edge_dirty = true;
}


#endif //PMESH_SURFACEMESH_IMPL_H
