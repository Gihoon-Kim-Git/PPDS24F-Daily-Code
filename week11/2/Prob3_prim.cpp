#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
   int mi_node(int n, int dist[], bool vis[]) { 
      int mi = INT_MAX; 
      int mi_idx = -1; 
      for (int i = 0; i < n; i++) { 
        if (vis[i] == false && dist[i] < mi) { 
          mi = dist[i], mi_idx = i; 
        } 
      } 
      return mi_idx; 
    } 

    int prim(vector<vector<int>> &edges, int n) {
        int parent[n]; 
        int dist[n]; 
        bool vis[n]; 
        for (int i = 0; i < n; i++) { 
            dist[i] = numeric_limits<int>::max(); 
            vis[i] = false; 
        } 
        parent[0] = -1; 
        dist[0] = 0; 
        for (int i = 0; i < n - 1; i++) { 
            int u = mi_node(n, dist, vis); 
            vis[u] = true; 
            for (int v = 0; v < n; v++) { 
              if (edges[u][v] && vis[v] == false &&  edges[u][v] < dist[v]) { 
                dist[v] = edges[u][v]; 
                parent[v] = u; 
              } 
            } 
          } 
          int cost = 0; 
          for (int i = 1; i < n; i++) {
              cost += edges[parent[i]][i];
          }
        return cost;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(); 
        vector<vector<int>> edges(n, vector<int>(n));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int w = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges[i][j] = w;
            }
        }
        return prim(edges, n);
    }
};