/*
You are given an array points representing integer coordinates of some points on
a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan
distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute
value of val.

Return the minimum cost to make all points connected. All points are connected
if there is exactly one simple path between any two points.

Example 1:

Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20

Example 2:

Input: points = [[3,12],[-2,5],[-4,1]]
Output: 18
*/
#include <cassert>
#include <queue>
#include <vector>

using namespace std;

// Kruskal
class UnionFind {
 private:
  vector<int> parent;
  vector<int> rank;

 public:
  UnionFind(int n) : parent(n), rank(n, 0) {
    int i = 0;
    generate(parent.begin(), parent.end(), [i]() mutable { return i++; });
  }

  int Find(int u) {
    if (parent[u] != u) {
      parent[u] = Find(parent[u]);
    }
    return parent[u];
  }

  void Union(int u, int v) {
    u = Find(u);
    v = Find(v);

    if (u == v) return;
    if (rank[u] > rank[v]) {  // Make higher rank parent
      parent[v] = u;
    } else if (rank[u] < rank[v]) {
      parent[u] = v;
    } else {  // else increase rank
      parent[v] = u;
      rank[u]++;
    }
  }
};

struct PqElement {
  int cost;
  int i;
  int j;
  bool operator>(const PqElement& rhs) const { return cost > rhs.cost; }
};

int Distance(const vector<int>& p1, const vector<int>& p2) {
  return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
}

int minCostConnectPoints(vector<vector<int>>& points) {
  int n = points.size();

  priority_queue<PqElement, vector<PqElement>, greater<PqElement>> pq;
  UnionFind uf{n};

  // Push all edge combinations
  for (int i = 0; i < n; ++i) {
    const auto& vi = points[i];
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      PqElement e{Distance(vi, points[j]), i, j};
      pq.push(std::move(e));
    }
  }

  int num_edges = 0;
  int total_dist = 0;

  while (num_edges < n - 1) {
    PqElement e = pq.top();
    pq.pop();

    if (uf.Find(e.i) != uf.Find(e.j)) {
      uf.Union(e.i, e.j);
      ++num_edges;
      total_dist += e.cost;
    }
  }

  return total_dist;
}

int main() {
  vector<vector<int>> points1{{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
  assert(minCostConnectPoints(points1) == 20);

  vector<vector<int>> points2{{3, 12}, {-2, 5}, {-4, 1}};
  assert(minCostConnectPoints(points2) == 18);
}