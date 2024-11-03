/*
There is a bi-directional graph with n vertices, where each vertex is labeled
from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D
integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional
edge between vertex ui and vertex vi. Every vertex pair is connected by at most
one edge, and no vertex has an edge to itself.

You want to determine if there is a valid path that exists from vertex source to
vertex destination.

Given edges and the integers n, source, and destination, return true if there is
a valid path from source to destination, or false otherwise.

Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
Output: true
Explanation: There are two paths from vertex 0 to vertex 2:
- 0 → 1 → 2
- 0 → 2

Input: n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0, destination =
5
Output: false
Explanation: There is no path from vertex 0 to vertex 5.
*/
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

bool Helper(const vector<vector<int>>& adj, int s, int d,
            vector<bool>& visited) {
  if (s == d) return true;
  visited[s] = true;

  for (int neigh : adj[s]) {
    if (visited[neigh]) continue;
    bool res = Helper(adj, neigh, d, visited);
    if (res) return true;
  }
  return false;
}

bool ValidPath(int n, vector<vector<int>>& edges, int source, int destination) {
  vector<bool> visited(n, false);
  vector<vector<int>> adj(n);
  for (const auto& edge : edges) {
    int u = edge[0], v = edge[1];
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  return Helper(adj, source, destination, visited);
}

int main() {
  vector<vector<int>> edges1{{0, 1}, {1, 2}, {2, 0}};
  assert(ValidPath(3, edges1, 0, 2) == true);

  vector<vector<int>> edges2{{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}};
  assert(ValidPath(6, edges2, 0, 5));
}
