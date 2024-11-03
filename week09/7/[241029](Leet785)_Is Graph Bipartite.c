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

/* 문제풀이
    1. dfs(v)를 활용한다.
        v의 neighbor에 대해서
            if neighbor가 미방문이면 -> v와 반대색상으로 coloring 후, 해당을 시점으로 dfs(nighbor)를 수행. 그리고 그 dfs(neighbor) 값이 만약에 False이면 return False
            else if neighbor가 이미 방문되었다면 -> v와 색상이 같다면 return False
        위 과정이 모두 끝났다면 return True
    2. 모든 노드를 시작점으로 dfs(i) 진행하고, 만약에 중간에 dfs(i)값이 False가 나오면 바로 return False.
        중간에 false 반환하지 않고 끝까지 진행된다면 return True
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool dfs(int** graph, int graphSize, int* graphColSize, int* visited, int vertex){
    for (int i = 0; i < graphColSize[vertex] ; i++){
        int neigh = graph[vertex][i];
        if (visited[neigh] == 0) {
            visited[neigh] = -visited[vertex];
            if (dfs(graph, graphSize, graphColSize, visited, neigh) == false) return false;
        } else if (visited[neigh] == visited[vertex]) return false;
    }
    return true;
}

bool isBipartite(int** graph, int graphSize, int* graphColSize) {
    int* visited = (int*)malloc(sizeof(int)*graphSize);
    for (int i = 0; i < graphSize; i++) visited[i] = 0;

    for (int v = 0; v < graphSize; v++){
        if (visited[v] == 0)
            visited[v] = 1; //첫방문시에는 1로 지정.
        if (dfs(graph, graphSize, graphColSize, visited, v) == false) {
            free(visited);
            return false;
        }
    }
    free(visited);
    return true;
}