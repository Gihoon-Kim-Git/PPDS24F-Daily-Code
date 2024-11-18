#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int mst_cost = 0;
        
        // make set
        unordered_map<int, int> sets;
        for (size_t i=0; i<points.size(); i++) {
            sets[i] = i;
        }

        // sort edges list
        vector<tuple<int, int, int>> edges;
        for (int i=0; i<points.size(); i++) {
            for (int j=i+1; j<points.size(); j++) {
                edges.push_back({distance(points[i], points[j]), i, j});
            }
        }
        sort(edges.begin(), edges.end());

        // Union-Find : 아래 구조체 바인딩 const auto& [...] 은 c++17 부터 지원
        // - 구조체 바인딩 대체 (c++11)
        // -- for (const auto& edge : edges) {
        // --     int weight = get<0>(edge);
        // --     int u = get<1>(edge);
        // --     int v = get<2>(edge);
        // --     ...
        // -- }
        for (const auto& [weight, u, v] : edges) {
            // Find
            if (findSet(sets, u) != findSet(sets, v)) {
                // Add
                mst_cost += weight;
                // Union
                // sets[findSet(sets, v)] = findSet(sets, u);
                unionSet(sets, u, v);
            }
        }
        
        return mst_cost;
    }

    int distance (vector<int>& p1, vector<int>& p2) {
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }

    int findSet (unordered_map<int, int>& sets, int u) {
        // 경로 압축
        if (sets[u] != u) {
            sets[u] = findSet(sets, sets[u]);
        }
        return sets[u];
    }

    void unionSet(unordered_map<int, int>& sets, int u, int v) {
        sets[findSet(sets, v)] = findSet(sets, u);
    }
};
