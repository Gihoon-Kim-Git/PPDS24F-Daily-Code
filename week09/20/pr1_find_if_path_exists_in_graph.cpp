using namespace std;
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>> graph;
        for(auto vec : edges){
            graph[vec[0]].push_back(vec[1]);
            graph[vec[1]].push_back(vec[0]);
        }
        
        queue<int> q;
        unordered_set<int> visited;

        q.push(source);
        visited.insert(source);

        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(node == destination) return true;

            for(int x : graph[node]){
                if(visited.find(x) == visited.end()){
                    visited.insert(x);
                    q.push(x);}
            }
        }
        return false;
    }
};