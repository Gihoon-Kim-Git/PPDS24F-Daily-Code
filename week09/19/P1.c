#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* dfs_util(int** edges, int edgesSize, int* visited, int v) {
    visited[v] = 1;
    for (int i=0; i<edgesSize; i++) {
        if (edges[i][0] == v && !(visited[edges[i][1]])) {
            visited = dfs_util(edges, edgesSize, visited, edges[i][1]);
        }
        if (edges[i][1] == v && !(visited[edges[i][0]])) {
            visited = dfs_util(edges, edgesSize, visited, edges[i][0]);
        }
    }
    return visited;
}

bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination)
{
    int visited[n];
    for (int i=0; i<n; i++) visited[i] = 0;
    int* answer = dfs_util(edges, edgesSize, visited, source);
    return answer[destination];
}

int main() {
    int n = 6;
    int arr1[2] = {0,1};
    int arr2[2] = {0,2};
    int arr3[2] = {3,5};
    int arr4[2] = {5,4};
    int arr5[2] = {4,3};
    int *edges[5] = {arr1, arr2, arr3, arr4, arr5};
    int edgesSize = sizeof(edges)/sizeof(arr1);
    int edgesColSize = sizeof(arr1)/sizeof(int);
    int source = 0;
    int destination = 5;
    printf("%d\n", validPath(n, edges, edgesSize, &edgesColSize, source, destination));

    return 0;
}