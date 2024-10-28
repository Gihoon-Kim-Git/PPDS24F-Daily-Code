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
    1. edges를 돌면서 adj_list 형성
    2. source를 시작으로 dfs 수행
    3. dfs 종료 후에 return visited[destination]
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 1) 초안 : 23/34 passed. (n이 100000인 경우에 memory limit exceeded) <- adj_list 초기화 방식 때문인 것으로 보임.
void dfs_util(int vertex, int** adj_list, int* adj_num, int* visited){
    visited[vertex] = 1;

    for (int i = 0; i < adj_num[vertex]; i++){
        int cur_neigh = adj_list[vertex][i];
        if (visited[cur_neigh] == 0){
            dfs_util(cur_neigh, adj_list, adj_num, visited);
        }
    }
}

bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination){
    //1. edges 돌면서 adj_list 형성
    int** adj_list = (int**)malloc(sizeof(int*) * n);
    int* adj_num = (int*)malloc(sizeof(int)*n);

    for (int i = 0; i < n; i++){
        adj_list[i] = (int*)malloc(sizeof(int) * n); // // 모든 정점이 서로 연결될 수 있는 최악의 경우를 가정
        adj_num[i] = 0;
    }

    for (int i = 0; i < edgesSize; i++){
        adj_list[edges[i][0]][adj_num[edges[i][0]]] = edges[i][1];
        adj_num[edges[i][0]]++;
        adj_list[edges[i][1]][adj_num[edges[i][1]]] = edges[i][0];
        adj_num[edges[i][1]]++;
    }

    //2. dfs 수행
    int* visited = (int*)malloc(sizeof(int)*n);
    for (int i = 0; i < n;i++) {
        visited[i] = 0;
    }

    dfs_util(source, &adj_list, adj_num, &visited);

    // 메모리 정리
    for (int i = 0; i < n; i++) {
        free(adj_list[i]);
    }
    free(adj_list);
    free(adj_num);
    
    //3. visited[destination] 확인 및 결과 return
    return visited[destination] == 1 ? true : false;
}

// 2) adj_list를 동적할당하도록.   => 100% 통과

void dfs_util(int vertex, int** adj_list, int* adj_num, int* visited){
    visited[vertex] = 1;

    for (int i = 0; i < adj_num[vertex]; i++){
        int cur_neigh = adj_list[vertex][i];
        if (visited[cur_neigh] == 0){
            dfs_util(cur_neigh, adj_list, adj_num, visited);
        }
    }
}

void addEdge(int **adj_list, int* adj_num, int fromV, int toV){
    adj_list[fromV][adj_num[fromV]] = toV;
    adj_num[fromV]++;
}

bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination){
    //1. edges 돌면서 adj_list 형성
    int** adj_list = (int**)malloc(sizeof(int*) * n);
    int* adj_num = (int*)calloc(n, sizeof(int));  //0으로 초기화함.
    int* adjLsize = (int*)malloc(sizeof(int) * n); //인접노드의 개수 관리.

    for (int i = 0; i < n; i++){
        adj_list[i] = (int*)malloc(sizeof(int) *1); //초기 크기를 1로
        adjLsize[i] = 1;
    }

    for (int i = 0; i < edgesSize; i++){
        int fromV = edges[i][0];
        int toV = edges[i][1];

        //배열이 꽉찼을 때 확장
        if (adj_num[fromV] == adjLsize[fromV]){
            adjLsize[fromV] *= 2;
            adj_list[fromV] = (int*)realloc(adj_list[fromV], sizeof(int)*adjLsize[fromV]);
        }
        if (adj_num[toV] == adjLsize[toV]){
            adjLsize[toV] *= 2;
            adj_list[toV] = (int*)realloc(adj_list[toV], sizeof(int)*adjLsize[toV]);
        }

        addEdge(adj_list, adj_num, fromV, toV);
        addEdge(adj_list, adj_num, toV, fromV);
    }

    //2. dfs
    int* visited = (int*)calloc(n, sizeof(int)); //0으로 초기화
    dfs_util(source, adj_list, adj_num, visited);

    bool result = visited[destination];
    for (int i = 0; i < n ; i++) free (adj_list[i]);
    free(adj_list);
    free(adjLsize);
    free(adj_num);
    free(visited);

    return result;
}


// 3) 고정배열 활용방법 : n이 5000, 10000 이렇게 큰 경우에는 고정배열 쓰는 방법이 매우 비효율적임. (sparse해서 저장공간 많이 필요없더라도 공간잡아먹으니까)
// 결과 : 21/34
bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination) {
    // 인접 리스트를 배열로 구현
    int adjList[2000][2000]; // 각 노드에 연결된 다른 노드들을 저장
    int adjSize[2000]; // 각 노드에 연결된 노드의 수를 저장

    // 인접 리스트 초기화
    for (int i = 0; i < n; i++) {
        adjSize[i] = 0;
    }

    // 인접 리스트 구성
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u][adjSize[u]++] = v;
        adjList[v][adjSize[v]++] = u;
    }

    bool visited[2000] = { false };
    int queue[2000];
    int front = 0, rear = 0;

    queue[rear++] = source;
    visited[source] = true;

    while (front < rear) {
        int node = queue[front++];
        if (node == destination) return true;

        for (int i = 0; i < adjSize[node]; i++) {
            int neighbor = adjList[node][i];
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                queue[rear++] = neighbor;
            }
        }
    }

    return false;
}