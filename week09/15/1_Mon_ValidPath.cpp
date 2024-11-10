#include <vector>

using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> neighbors(n);
        for (const auto& edge : edges) {
            neighbors[edge[0]].push_back(edge[1]);
            neighbors[edge[1]].push_back(edge[0]);
        }

        vector<bool> visit(n, false);
        dfs(source, neighbors, visit);
        return visit[destination];
    }
    void dfs(int node, const vector<vector<int>>& neighbors, vector<bool>& visit) {
        visit[node] = true;
        for (int neighbor : neighbors[node]) {
            if (!visit[neighbor]) {
                dfs(neighbor, neighbors, visit);
            }
        }
    }
};