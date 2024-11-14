#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int u, v, weight;
} Edge;

int find(int parent[], int u) {
    if (parent[u] != u) parent[u] = find(parent, parent[u]);
    return parent[u];
}

int unionSets(int parent[], int rank[], int u, int v) {
    int rootU = find(parent, u);
    int rootV = find(parent, v);
    if (rootU != rootV) {
        if (rank[rootU] > rank[rootV]) parent[rootV] = rootU;
        else if (rank[rootU] < rank[rootV]) parent[rootU] = rootV;
        else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
        return 1;
    }
    return 0;
}

int compare(const void *a, const void *b) {
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize) {
    int n = pointsSize;
    Edge edges[n * (n - 1) / 2];
    int edgeCount = 0;

    // Collect all edges with Manhattan distances
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
            edges[edgeCount++] = (Edge){i, j, dist};
        }
    }

    // Sort edges by distance
    qsort(edges, edgeCount, sizeof(Edge), compare);
    
    int parent[n], rank[n], result = 0, count = 0;
    for (int i = 0; i < n; ++i) parent[i] = i, rank[i] = 0;

    // Kruskal's Algorithm
    for (int i = 0; i < edgeCount; ++i) {
        if (unionSets(parent, rank, edges[i].u, edges[i].v)) {
            result += edges[i].weight;
            count++;
            if (count == n - 1) break;
        }
    }

    return result;
}

// Example usage
int main() {
    int pointsSize = 5;
    int points[5][2] = {{0,0},{2,2},{3,10},{5,2},{7,0}};
    int *pointers[5];
    for (int i = 0; i < pointsSize; i++) {
        pointers[i] = points[i];
    }

    printf("Minimum cost to connect points: %d\n", minCostConnectPoints(pointers, pointsSize, NULL));
    return 0;
}
