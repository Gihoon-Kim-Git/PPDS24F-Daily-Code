#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool dfs_util(int** graph, int* visited, int v, int color, int* graphColSize) {
    visited[v] = color;
    for (int k=0; k<graphColSize[v]; k++) {
        if (visited[graph[v][k]] == color) return false;
        else if (visited[graph[v][k]] == 0) {
            if (!dfs_util(graph, visited, graph[v][k], -color, graphColSize)) return false;
        }
    }
    return true;
}

bool isBipartite(int** graph, int graphSize, int* graphColSize) {
    int visited[graphSize];
    for (int i=0; i<graphSize; i++) visited[i] = 0;
    for (int j=0; j<graphSize; j++) {
        if (visited[j] == 0 && !(dfs_util(graph, visited, j, 1, graphColSize))) return false;
    }
    return true;
}

int main() {
    int arr1[] = {1,3};
    int arr2[] = {0,2};
    int arr3[] = {1,3};
    int arr4[] = {0,2};
    int *graph[] = {arr1, arr2, arr3, arr4};
    int graphSize = sizeof(graph)/sizeof(graph[0]);
    int graphColSize[graphSize];
    for (int i=0; i<graphSize; i++) graphColSize[i] = sizeof(*graph[i])/sizeof(int);
    printf("%d\n", isBipartite(graph, graphSize, graphColSize));
    
    return 0;
}