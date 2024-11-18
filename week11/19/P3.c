#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int abs(int a) {
    return a < 0 ? -a : a;
}

int compare(const void* a, const void* b) {
    int *rowA = *(int **)a;
    int *rowB = *(int **)b;
    return rowA[0] - rowB[0];
}

int find(int v, int* parent) {
    if (parent[v] != v) parent[v] = find(parent[v], parent);
    return parent[v];
}

bool Union(int v, int w, int* parent) {
    int root_v = find(v, parent);
    int root_w = find(w, parent);
    if (root_v != root_w) {
        parent[root_w] = root_v;
        return true;
    }
    return false;
}

int minCostConnectPoints(int** points, int pointSize) { // Kruskal
    int edgeSize = pointSize * pointSize;
    int** edges = (int**)malloc(edgeSize * sizeof(int*));
    for (int i=0; i<pointSize; i++) {
        for (int j=0; j<pointSize; j++) {
            int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
            edges[i * pointSize + j] = (int*)malloc(3 * sizeof(int));
            edges[i * pointSize + j][0] = dist;
            edges[i * pointSize + j][1] = i;
            edges[i * pointSize + j][2] = j;
        }
    }

    qsort(edges, edgeSize, sizeof(edges[0]), compare);

    int* parent = (int*)malloc(pointSize * sizeof(int));
    for (int i=0; i<pointSize; i++) parent[i] = i;

    int min_cost = 0, edge_count = 0;
    for (int e=0; e<edgeSize; e++) {
        if (Union(edges[e][1], edges[e][2], parent)) {
            min_cost += edges[e][0];
            edge_count++;
            if (edge_count == pointSize - 1) break;
        }
    }

    for (int i = 0; i < edgeSize; i++) free(edges[i]);
    free(edges);
    free(parent);

    return min_cost;
}

int main() {
    int pointsData[5][2] = {{0,0},{2,2},{3,10},{5,2},{7,0}};
    int* points[5];
    for (int i=0; i<5; i++) points[i] = pointsData[i];
    printf("%d\n", minCostConnectPoints(points, 5));

    return 0;
}