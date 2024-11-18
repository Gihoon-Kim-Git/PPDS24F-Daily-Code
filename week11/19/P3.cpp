#include <iostream>
#include <queue>
using namespace std;

class Solution { // Prim
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> visited(n, 0);
        int min_cost = 0, edges = 0;

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> min_heap;
        min_heap.push({0, 0});

        while (edges < n) {
            vector<int> heap = min_heap.top();
            min_heap.pop();
            int cost = heap[0];
            int u = heap[1];

            if (visited[u]) continue;

            visited[u] = 1;
            min_cost += cost;
            edges++;

            for (int v=0; v<n; v++) {
                if (visited[v] == 0) {
                    int dist = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                    min_heap.push({dist, v});
                }
            }
        }

        return min_cost;
    }
};


int main() {
    vector<vector<int>> points = {{0,0},{2,2},{3,10},{5,2},{7,0}};
    Solution result;
    cout << result.minCostConnectPoints(points) << endl;

    return 0;
}