// //prim's algorithm
// #include <vector>
// #include <queue>
// #include <cmath>
// using namespace std;

// class Solution {
// public:
//     int minCostConnectPoints(vector<vector<int>>& points) {
//         int n = points.size();
//         vector<int> minDist(n, INT_MAX);  // Minimum distance to the MST
//         minDist[0] = 0;  // Start from the first point
//         vector<bool> inMST(n, false);  // Track points added to the MST
//         int totalCost = 0;
        
//         // Min-heap to store (cost, point_index) pairs
//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
//         pq.emplace(0, 0);
        
//         while (!pq.empty()) {
//             auto [cost, u] = pq.top();
//             pq.pop();
            
//             if (inMST[u]) continue;
//             inMST[u] = true;
//             totalCost += cost;
            
//             // Update the distances of all other points to the MST
//             for (int v = 0; v < n; ++v) {
//                 if (!inMST[v]) {
//                     int dist = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
//                     if (dist < minDist[v]) {
//                         minDist[v] = dist;
//                         pq.emplace(dist, v);
//                     }
//                 }
//             }
//         }
        
//         return totalCost;
//     }
// };

//kruskal algorithm
// #include <vector>
// #include <algorithm>
// #include <cmath>
// using namespace std;

// class UnionFind {
// public:
//     UnionFind(int n) : parent(n), rank(n, 1) {
//         for (int i = 0; i < n; ++i) {
//             parent[i] = i;
//         }
//     }
    
//     int find(int u) {
//         if (u != parent[u]) {
//             parent[u] = find(parent[u]);
//         }
//         return parent[u];
//     }
    
//     bool unite(int u, int v) {
//         int rootU = find(u);
//         int rootV = find(v);
        
//         if (rootU == rootV) return false;
        
//         if (rank[rootU] > rank[rootV]) {
//             parent[rootV] = rootU;
//         } else if (rank[rootU] < rank[rootV]) {
//             parent[rootU] = rootV;
//         } else {
//             parent[rootV] = rootU;
//             rank[rootU]++;
//         }
//         return true;
//     }
    
// private:
//     vector<int> parent;
//     vector<int> rank;
// };

// class Solution {
// public:
//     int minCostConnectPoints(vector<vector<int>>& points) {
//         int n = points.size();
//         vector<tuple<int, int, int>> edges;  // (distance, point1, point2)
        
//         // Step 1: Create all edges with Manhattan distances
//         for (int i = 0; i < n; ++i) {
//             for (int j = i + 1; j < n; ++j) {
//                 int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
//                 edges.emplace_back(dist, i, j);
//             }
//         }
        
//         // Step 2: Sort edges by distance
//         sort(edges.begin(), edges.end());
        
//         // Step 3: Use Union-Find to construct the MST
//         UnionFind uf(n);
//         int totalCost = 0;
//         int edgesUsed = 0;
        
//         for (const auto& [dist, u, v] : edges) {
//             if (uf.unite(u, v)) {
//                 totalCost += dist;
//                 edgesUsed++;
//                 if (edgesUsed == n - 1) break;  // Stop once we have n-1 edges in the MST
//             }
//         }
        
//         return totalCost;
//     }
// };

