/*You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points*/

#include <iostream>
#include <vector>
#include <algorithm>

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

struct DisjointSet {
    std::vector<int> parent, rank;
    DisjointSet(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int u) {
        if (u != parent[u]) parent[u] = find(parent[u]);  // Path compression
        return parent[u];
    }

    void unionSet(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);
        if (root_u != root_v) {
            if (rank[root_u] > rank[root_v]) parent[root_v] = root_u;
            else if (rank[root_u] < rank[root_v]) parent[root_u] = root_v;
            else {
                parent[root_v] = root_u;
                rank[root_u]++;
            }
        }
    }
};

std::vector<Edge> kruskal(int n, std::vector<Edge>& edges) {
    std::sort(edges.begin(), edges.end());
    DisjointSet dsu(n);
    std::vector<Edge> mst;
    
    for (auto& edge : edges) {
        if (dsu.find(edge.u) != dsu.find(edge.v)) {
            dsu.unionSet(edge.u, edge.v);
            mst.push_back(edge);
        }
    }
    
    return mst;
}

//절댓값(맨해튼 거리) 계산용으로 만든 함수
Edge make_edge_with_index(int i, int j, const std::vector<std::vector<int>>& points){
    int w_x = (points[i][0] - points[j][0]) > 0 ? points[i][0]-points[j][0] : - (points[i][0] - points[j][0]);
    int w_y = (points[i][1] - points[j][1]) > 0 ? points[i][1]-points[j][1] : - (points[i][1] - points[j][1]);

    Edge new_edge;
    new_edge.u = i;
    new_edge.v = j;
    new_edge.weight = w_x + w_y;

    return new_edge;
}

class Solution {
public:
    int minCostConnectPoints(std::vector<std::vector<int>>& points) {
        std::vector<Edge> edge_list;
        
        int num_points = points.size();
        for (int i = 0; i < num_points; i++){
            for (int j = 0; j < num_points; j++){
                edge_list.push_back(make_edge_with_index(i, j, points));
            }
        }

        std::vector<Edge> MST_edge = kruskal(num_points, edge_list);
        
        int sum = 0;
        for (auto e : MST_edge){
            sum += e.weight;
        }
        return sum;
    }
};


//Prim :참고
#include <vector>
#include <queue>
#include <utility>
#include <cmath>     // 혹은 #include <cstdlib> (절대값 함수 abs 사용)
#include <functional>  // 비교함수 greater<>를 사용할 때 필요
using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& nums) {
        int n=nums.size();
        int connected = 0, i=0;
        int ans=0;
        vector<bool> vis(n);
        priority_queue<pair<int,int>, vector<pair<int,int>>,
        greater<pair<int,int>>> pq;
        while(++connected < n){
            vis[i] = true;
            for(int j=0;j<n;j++){
                if(!vis[j]) 
                    pq.push({(abs(nums[j][0] - nums[i][0]) + 
                    abs(nums[i][1] - nums[j][1])), j});
            }

            while(vis[pq.top().second]) pq.pop();
            ans=ans+=pq.top().first;
            i = pq.top().second;
            pq.pop();
        }
        return ans;
    }
};