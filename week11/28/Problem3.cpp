#include <vector>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> visited(n, false);
        vector<int> minCost(n, INT_MAX);
        minCost[0] = 0;
        int result = 0;

        for (int i = 0; i < n; ++i) {
            int u = -1;
            for (int j = 0; j < n; ++j) {
                if (!visited[j] && (u == -1 || minCost[j] < minCost[u])) {
                    u = j;
                }
            }
            visited[u] = true;
            result += minCost[u];
            for (int v = 0; v < n; ++v) {
                if (!visited[v]) {
                    int dist = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                    minCost[v] = min(minCost[v], dist);
                }
            }
        }
        return result;
    }
};