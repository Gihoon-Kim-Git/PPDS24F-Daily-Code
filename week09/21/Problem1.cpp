#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
    vector<bool> vis(n,false);
    return dfshelp(adj, vis, source, destination);
    
    }

    bool dfshelp(vector<vector<int>> &adj, vector<bool> &vis, int source, int destination){
        if(source == destination) return true;
        vis[source] = true;

        for(int nxt : adj[source]){
            if(!vis[nxt]) {
                if(dfshelp(adj, vis, nxt, destination)) return true;
            }
        }
        return false;
    }

};