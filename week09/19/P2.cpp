#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> visited;

    bool dfs_util(vector<vector<int>>& graph, int v, int color) {
        bool bipartite = true;
        visited[v] = color;
        for (auto n: graph[v]) {
            if (visited[n] == color) return false;
            else if (visited[n] == 0) bipartite = dfs_util(graph, n, -color);
        }
        return bipartite;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        visited.resize(graph.size(), 0);
        for (int i=0; i<graph.size(); i++) {
            if (visited[i] == 0 && !(dfs_util(graph, i, 1))) return false;
        }
        return true;
    }
};

int main() {
    vector<vector<int>> graph = {{1,3}, {0,2}, {1,3}, {0,2}};
    Solution result;
    cout << result.isBipartite(graph) << endl;

    return 0;
}