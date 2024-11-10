class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n); 
        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n,false);
        queue<int> q;
        q.push(source);
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            visited[curr]=true;
            if(curr==destination){
                return true;
            }
            for(auto& it:adj[curr]){
                
                if(!visited[it]){
                    visited[it]=true;
                    q.push(it);
                }
            }
        }
        return false;
    }
};