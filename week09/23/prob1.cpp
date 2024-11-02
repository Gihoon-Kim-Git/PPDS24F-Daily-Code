#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    bool dfs(vector<vector<int>>& graph, int source, int destination, vector<int>& visited){
        if (source == destination){
            return true;
        }
        visited[source] = 1;
        for (auto& neighbor : graph[source]){
            if (visited[neighbor] == 0){
                if (dfs(graph, neighbor, destination, visited)){
                    return true;
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination){
        vector<vector<int>> graph(n);
        for (auto& edge: edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<int> visited(n, 0);

        return dfs(graph, source, destination, visited);
    }
};

int main(){
    vector<vector<int>> edges = {{0,1}, {0,2}, {3,5}, {5,4}, {4,3}};
    int n  = 6;
    bool res = Solution().validPath(n, edges, 0, 5);

    cout << "The result is: " << res << endl;
}