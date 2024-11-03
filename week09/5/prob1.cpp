#include <vector>
using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        vector<vector<int>> adj = convertEdgesToAdj(n, edges);
        vector<bool> visited(n, false);

        return dfs_helper(source, destination, adj, visited);
    }

    vector<vector<int>> convertEdgesToAdj (int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (vector<int> edge : edges) {
            adj[edge.front()].push_back(edge.back());
            adj[edge.back()].push_back(edge.front());
        }
        return adj;
    }

    bool dfs_helper(int curr, int destination, const vector<vector<int>>& adj, vector<bool>& visited) {
        visited[curr] = true;

        // base case
        if (curr == destination) {
            return true;
        }
        
        // recursive case
        for (int neighbor : adj[curr]) {
            if (!visited[neighbor]) {
                if (dfs_helper(neighbor, destination, adj, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};
