/*문제
here is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:
    There are no self-edges (graph[u] does not contain u).
    There are no parallel edges (graph[u] does not contain duplicate values).
    If v is in graph[u], then u is in graph[v] (the graph is undirected).
    The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.

A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

Return true if and only if it is bipartite.

"""Constraints
    graph.length == n
    1 <= n <= 100
    0 <= graph[u].length < n
    0 <= graph[u][i] <= n - 1
    graph[u] does not contain u.
    All the values of graph[u] are unique.
    If graph[u] contains v, then graph[v] contains u."""
*/

/*풀이
    1. dfs(i, visited, color))
        visited[i] = color
        i의 모든 neighbor에 대해 다음을 진행
            if visited[neighbor]== 0 -> visited[neighbor] = -color
                                    ->if (dfs(neighbor, visited, -color) == false) return false
            else if visited[neighbor] == color -> return false
        return true
    2. 모든 노드v에 대해 dfs를 진행하는데, 첫 방문일 경우에는 색상 지정. 첫방문이 아니면, if dfs(v)== false이면 return false로 중단.
        중간에 중단되지 않고 끝까지 dfs 돌았으면 return true;
*/

#include <iostream>
#include <vector>
using namespace std;

//처음에 time limit exceeded 나옴. 왜냐면. dfs argument로 visited를 &visited 안 해줘서 매번 복사했기 때문...
class Solution {
public:
    bool dfs(vector<vector<int>> &graph, vector<int> &visited, int vertex, int color){ 
        visited[vertex] = color;
        for (int neigh : graph[vertex]){
            if (visited[neigh] == 0){
                visited[neigh] = -color;
                if (dfs(graph, visited,neigh, -color) == false) return false;
            } else if (visited[neigh] == color) return false;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> visited(graph.size(), 0);

        for (int i = 0 ; i < graph.size(); i++){
            if (visited[i] == 0) 
                if (dfs(graph, visited, i, 1) == false) return false;
        }
        return true;
    }
};