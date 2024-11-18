#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

class UnionFind {
public:
    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int u) {
        if (parent[u] != u) parent[u] = find(parent[u]);
        return parent[u];
    }

    bool unionSets(int u, int v) {
        int rootU = find(u), rootV = find(v);
        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) parent[rootV] = rootU;
            else if (rank[rootU] < rank[rootV]) parent[rootU] = rootV;
            else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
            return true;
        }
        return false;
    }

private:
    std::vector<int> parent, rank;
};

int minCostConnectPoints(std::vector<std::vector<int>>& points) {
    int n = points.size();
    std::vector<std::tuple<int, int, int>> edges;

    // Collect all edges and calculate Manhattan distances
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
            edges.emplace_back(dist, i, j);
        }
    }

    // Sort edges by distance
    std::sort(edges.begin(), edges.end());
    UnionFind uf(n);
    int result = 0, count = 0;

    // Kruskal's Algorithm
    for (const auto& [dist, u, v] : edges) {
        if (uf.unionSets(u, v)) {
            result += dist;
            count++;
            if (count == n - 1) break;
        }
    }

    return result;
}

// Example usage
int main() {
    std::vector<std::vector<int>> points = {{0,0},{2,2},{3,10},{5,2},{7,0}};
    std::cout << "Minimum cost to connect points: " << minCostConnectPoints(points) << std::endl;
    return 0;
}
