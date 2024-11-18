#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

/*
 * Problem Description:
 * --------------------
 * You are given an array points representing integer coordinates of some points on a 2D-plane,
 * where points[i] = [xi, yi].
 *
 * The cost of connecting two points [xi, yi] and [xj, yj] is the Manhattan distance between them:
 * |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.
 *
 * Return the minimum cost to make all points connected. All points are connected if there is exactly
 * one simple path between any two points.
 *
 * Example:
 * --------
 * Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
 * Output: 20
 *
 * Constraints:
 * ------------
 * 1 <= points.length <= 1000
 * -10^6 <= xi, yi <= 10^6
 * All pairs (xi, yi) are distinct.
 */

class Solution {
public:
    struct Edge {
        int x, y, cost;
    };

    static int manhattan_distance(vector<int>& point_i, vector<int>& point_j) {
        return abs(point_i[0] - point_j[0]) + abs(point_i[1] - point_j[1]);
    }

    static bool compare(Edge& a, Edge& b) {
        return a.cost < b.cost;
    }

    int find_set(vector<int>& parent_set, int x) {
        if (parent_set[x] != x) {
            parent_set[x] = find_set(parent_set, parent_set[x]);
        }
        return parent_set[x];
    }

    void union_set(vector<int>& parent_set, vector<int>& rank, int x, int y) {
        int root_x = find_set(parent_set, x);
        int root_y = find_set(parent_set, y);

        if (root_x != root_y) {
            if (rank[root_x] > rank[root_y]) {
                parent_set[root_y] = root_x;
            } else if (rank[root_x] < rank[root_y]) {
                parent_set[root_x] = root_y;
            } else {
                parent_set[root_y] = root_x;
                rank[root_x]++;
            }
        }
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<Edge> edges;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                edges.push_back({i, j, manhattan_distance(points[i], points[j])});
            }
        }

        sort(edges.begin(), edges.end(), compare);

        vector<int> parent_set(n);
        vector<int> rank(n, 0);
        for (int i = 0; i < n; ++i) {
            parent_set[i] = i;
        }

        int min_cost = 0, edges_used = 0;
        for (auto& edge : edges) {
            if (edges_used == n - 1) break;

            int u = edge.x, v = edge.y;
            if (find_set(parent_set, u) != find_set(parent_set, v)) {
                min_cost += edge.cost;
                union_set(parent_set, rank, u, v);
                edges_used++;
            }
        }

        return min_cost;
    }
};