#include <iostream>
#include <vector>

class Solution {
public:
    bool dfs(int curr, int destination, vector<vector<int>>& adj, vector<bool>& visited){
        if(curr == destination) {
            return true;
        }
        visited[curr] = true;
        for(int i = 0; i < adj[curr].size(); ++i){
            int neighbor = adj[curr][i];
            if(!visited[neighbor]){
                if(dfs(neighbor, destination, adj, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n, vector<int>());
        for(int i=0; i<edges.size(); ++i){
            vector<int> e = edges[i];
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, 0);
        return dfs(source, destination, adj, visited);
    }
    
    
};