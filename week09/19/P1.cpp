#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> visited;
    vector<vector<int>> adj;

    void dfs_util(int v) {
        visited[v] = 1;
        for (auto i: adj[v]) {
            if (!visited[i]) dfs_util(i);
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        visited.resize(n, 0);
        adj.resize(n);
        for (auto i: edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        dfs_util(source);
        return visited[destination];
    }
};

int main() {
    int n = 6;
    vector<vector<int>> edges = {{0,1}, {0,2}, {3,5}, {5,4}, {4,3}};
    int source = 0;
    int destination = 5;
    Solution result;
    cout << result.validPath(n, edges, source, destination) << endl;

    return 0;
}