/* 
Leetcode 1584. Min Cost to Connect All Points

Minimum Spanning Tree
Union-Find => cycle이 없게하는것
*/

/*
내가 생각하는 접근법
1. graph construction with manhattan distance
    각 정점이 자신을 제외한 다른 정점들과 전부 연결되어있고, weight가 맨하탄 dist로 가정
2. PrimMST or Kruskal로 풀기
*/

/*
// PrimMST
#include <vector>
#include <queue>
#include <cmath>
#include <limits>

using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int numPts = points.size();
        if (numPts == 0) return 0;

        // Min-heap to store {cost, point_index}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        vector<bool> inMST(numPts, false); // To track if a point is included in MST
        int totalCost = 0;
        int edgesUsed = 0;

        // Start with the first point (index 0)
        minHeap.push({0, 0}); // Cost to reach the first point is 0

        while (edgesUsed < numPts) {
            auto [cost, u] = minHeap.top();
            minHeap.pop();

            // If the point is already included in MST, skip it
            if (inMST[u]) {
                continue;
            }

            // Include this point in MST
            inMST[u] = true;
            totalCost += cost;
            edgesUsed++;

            // Update the heap with the cost of connecting the next points
            for (int v = 0; v < numPts; v++) {
                if (!inMST[v]) {
                    int manhDist = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                    minHeap.push({manhDist, v});
                }
            }
        }

        return totalCost;
    }
};

*/

/*
// kruskal
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Edge {
    int u;
    int v;
    int weight;
    
    // Comparator for sorting edges by weight
    static bool compareEdge(const Edge& e1, const Edge& e2) {
        return e1.weight < e2.weight;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int numPts = points.size();
        if (numPts == 0) return 0;

        // Create all edges with their Manhattan distances
        vector<Edge> edges;
        for (int i = 0; i < numPts - 1; i++) {
            for (int j = i + 1; j < numPts; j++) {
                int manhDist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({i, j, manhDist});
            }
        }

        // Sort all edges by weight
        sort(edges.begin(), edges.end(), Edge::compareEdge);

        // Initialize Union-Find structures
        vector<int> parent(numPts);
        vector<int> rank(numPts, 1);
        for (int i = 0; i < numPts; i++) {
            parent[i] = i;
        }

        int totalCost = 0;
        int edgesUsed = 0;

        // Kruskal's algorithm to find MST
        for (const auto& edge : edges) {
            if (findParent(edge.u, parent) != findParent(edge.v, parent)) {
                unionNodes(edge.u, edge.v, parent, rank);
                totalCost += edge.weight;
                edgesUsed++;
                if (edgesUsed == numPts - 1) break;
            }
        }

        return totalCost;
    }

private:
    // Find function with path compression
    int findParent(int node, vector<int>& parent) {
        if (parent[node] != node) {
            parent[node] = findParent(parent[node], parent); // Path compression
        }
        return parent[node];
    }

    // Union function with rank
    void unionNodes(int u, int v, vector<int>& parent, vector<int>& rank) {
        int rootU = findParent(u, parent);
        int rootV = findParent(v, parent);

        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

*/

// 성은의 풀이
#include <unordered_map>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;
struct Edge
{
    vector<int> p1;
    vector<int> p2;
    int dist;
    static bool compareEdge(const Edge& e1, const Edge& e2) {
    return e1.dist < e2.dist;
}
};


class Solution {
public:
    struct VectorHash {
    size_t operator()(const vector<int>& v) const {
        size_t result = 0;  // 변수 이름을 'result'로 변경하여 'hash'와 혼동되지 않도록 함
        for (int i : v) {
            result ^= result * 31 + std::hash<int>()(i);
        }
        return result;
    }
};
    int minCostConnectPoints(vector<vector<int>>& points) {
        int numPts=points.size();
        //unordered_map<vector<int>,int> key(numPts,kInf);
        //unordered_map<vector<int>,vector<int>> prev(numPts);

        int cost_sum=0;

        unordered_map<vector<int>,int,VectorHash> group;
        
        for(int i=0;i<numPts;i++)
        {
            group[points[i]]=i;
        }
        vector<Edge> edges;
        for(int i=0; i<numPts-1; i++)
        {
            for(int j=i+1; j<numPts;j++)
            {
                int manh_dist = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                edges.push_back({points[i],points[j],manh_dist});
            }
        }
        sort(edges.begin(),edges.end(),Edge::compareEdge);
        for(auto &e : edges)
        {
            if(Connected(e.p1,e.p2,group))
            {
                continue;
            }
            Union(e.p1,e.p2,group);
            cost_sum += e.dist;

        }
        return cost_sum;
    }
    
    int Find(vector<int> &p, unordered_map<vector<int>,int,VectorHash> &group)
    {
        return group[p]; 
    }
    bool Connected(vector<int> &p,vector<int> &q, unordered_map<vector<int>,int,VectorHash> &group)
    {
        return group[p] == group[q];
    }
    void Union(vector<int> &p,vector<int> &q, unordered_map<vector<int>,int,VectorHash> &group)
    {
        int pid = Find(p, group);
        int qid = Find(q, group);

        if(group[p]==group[q])
        {
            return;
        }

        for (auto elem: group)
        {
            if(elem.second==pid)
            {
                group[elem.first]=qid;
            }
        }

    }
};