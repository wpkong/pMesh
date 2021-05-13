/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/13
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#ifndef PMESH_UTILS_H
#define PMESH_UTILS_H

#include <utility>
#include <set>
#include <vector>
#include <map>

using std::vector;
typedef std::pair<int, int> vertex_pair;

inline vector<std::deque<vertex_pair>> convert_edges_to_chains(std::set<vertex_pair> &edges) {
    vector<std::deque<vertex_pair>> chains;
    vector<vertex_pair> boundary_edges(edges.begin(), edges.end());
    std::map<int, vector<int>> point_to_edges;
    for (int e = 0; e < boundary_edges.size(); ++e) {
        point_to_edges[boundary_edges[e].first].push_back(e);
        point_to_edges[boundary_edges[e].second].push_back(e);
    }
    std::set<vertex_pair> edge_set(edges.begin(), edges.end());
    while (!edge_set.empty()) {
        std::deque<vertex_pair> chain;
        chain.push_back(*edge_set.begin());
        edge_set.erase(edge_set.begin());
        while (!edge_set.empty() && point_to_edges[chain.back().second].size() == 2) {
            int before_len = edge_set.size();
            for (auto it = edge_set.begin(); it != edge_set.end(); ++it) {
                if (it->first == chain.back().second) {
                    chain.push_back(*it);
                    edge_set.erase(it);
                    break;
                }
                if (it->second == chain.back().second) {
                    chain.emplace_back(it->second, it->first);
                    edge_set.erase(it);
                    break;
                }
            }
            if (before_len == edge_set.size()) break;
        }

        while (!edge_set.empty() && point_to_edges[chain.front().first].size() == 2) {
            int before_len = edge_set.size();
            for (auto it = edge_set.begin(); it != edge_set.end(); ++it) {
                if (it->first == chain.front().first) {
                    chain.push_front(std::make_pair(it->second, it->first));
                    edge_set.erase(it);
                    break;
                }
                if (it->second == chain.front().first) {
                    chain.push_front(*it);
                    edge_set.erase(it);
                    break;
                }
            }
            if (before_len == edge_set.size()) break;
        }

        chains.push_back(chain);
    }
    return std::move(chains);
}

#endif //PMESH_UTILS_H
