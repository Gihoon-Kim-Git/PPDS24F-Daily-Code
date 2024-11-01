#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, -1);  

        for (int i = 0; i < n; ++i) {
            if (colors[i] == -1) {  
                queue<int> q;
                q.push(i);
                colors[i] = 0; 

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (int neighbor : graph[node]) {
                        if (colors[neighbor] == -1) {  
                            colors[neighbor] = 1 - colors[node];  
                            q.push(neighbor);
                        } 
                        else if (colors[neighbor] == colors[node]) {
                            return false;  
                        }
                    }
                }
            }
        }

        return true;  
    }
};