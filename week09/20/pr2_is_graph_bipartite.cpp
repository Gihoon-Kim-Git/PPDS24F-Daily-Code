#include <vector>
#include <unordered_map>
using namespace std;
#include <stack>
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        //Stack으로 풀어봅세
        unordered_map<int,int> color;
        for(int i=0;i<n;i++) color[i] = -1;
        stack<pair<int,int>> node;
        for(int j=0;j<n;j++){
            if(color[j]==-1){
                node.push({j,0});
                while(!node.empty()){
                    int curr = node.top().first;
                    int col = node.top().second;
                    node.pop();
                    if(color[curr] == -1) color[curr] = col;
                    else if(color[curr] != col) return false;

                    for(int neighbor : graph[curr]){
                        if(color[neighbor]==col) return false;
                        else if(color[neighbor]==-1){
                            node.push({neighbor,1-col});
                        }
                    }
                }
            }
        }
        return true;
    }
};