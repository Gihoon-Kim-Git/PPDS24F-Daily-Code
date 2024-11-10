/*"""문제
There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

You want to determine if there is a valid path that exists from vertex source to vertex destination.

Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise.
"""
"""Constraint
    1 <= n <= 2 * 105
    0 <= edges.length <= 2 * 105
    edges[i].length == 2
    0 <= ui, vi <= n - 1
    ui != vi
    0 <= source, destination <= n - 1
    There are no duplicate edges.
    There are no self edges.
"""*/

/*문제풀이
    1. edges를 기반으로 adj_list 정리.
    2. dfs를 수행한다. 이때 outer loop은 제외하고 source를 시작으로 dfs를 수행한다.
    3. 2가 끝난 후에 visited[destination]의 결과를 반환한다.*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    void dfs_util(int v, vector<vector<int>> &adj_list, vector<bool> &visited){
        visited[v] = true;

        for (int neigh:adj_list[v]){
            if (!visited[neigh])
                dfs_util(neigh, adj_list, visited);
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination){
        //1. adj_list 정리
        vector<vector<int>> adj_list(n, vector<int>());

        for (auto e : edges){
            adj_list[e[0]].push_back(e[1]);
            adj_list[e[1]].push_back(e[0]);
        }
        
        //2. dfs수행
        vector<bool> visited(n, false);
        
        dfs_util(source, adj_list, visited);

        //3. dfs수행 후 visited[destination] 상태 확인
        return visited[destination];
    }
};


//방법2 : dfs_util 수행 간 destnaiton을 식별해서 true, false 반환
class Solution{
public:
    bool dfs_util(int v, vector<vector<int>> &adj_list, vector<bool> &visited, int destination){
        if (v == destination) return true;

        visited[v] = true;
        
        for (int neigh:adj_list[v]){
            if (!visited[neigh])
                if (dfs_util(neigh, adj_list, visited, destination)) return true;
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination){
        //1. adj_list 정리
        vector<vector<int>> adj_list(n, vector<int>());

        for (auto e : edges){
            adj_list[e[0]].push_back(e[1]);
            adj_list[e[1]].push_back(e[0]);
        }
        
        //2. dfs수행
        vector<bool> visited(n, false);
        
        return dfs_util(source, adj_list, visited, destination);
    }
};