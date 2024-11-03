#include <bits/stdc++.h>
#include <queue>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        queue<pair<int,int>> q;
        for(int i=0; i<n; i++){
            if(color[i] == -1){
                q.push({i,1});
                while(!q.empty()){
                    auto f = q.front();
                    int idx = f.first;
                    int coloridx = f.second;
                    q.pop();
                    color[idx] = coloridx;
                    for(auto i : graph[idx]){
                        if(color[i] == -1) q.push({i, 1-coloridx});
                        else if(color[i] == color[idx]) return false;
                    }
                }
            }
        }
        return true;
    }
};