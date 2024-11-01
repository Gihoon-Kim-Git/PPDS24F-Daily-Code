#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool bfs(int **graph, int* color, int graphSize, int* graphColSize, int start) {
    int queue[graphSize + 1];
    int front = 0;
    int rear = 0;
    color[start] = 0;
    queue[++rear] = start;

    while (front != rear) {
        int current = queue[++front];
        int size = graphColSize[current];
        for (int i = 0; i < size; i++) {
            int neighbor = graph[current][i];
            if (color[neighbor] == -1) {
                color[neighbor] = 1 - color[current];
                queue[++rear] = neighbor;
            } else if (color[neighbor] == color[current]) {
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(int** graph, int graphSize, int* graphColSize) {
    int *color = (int *)malloc(sizeof(int) * graphSize);
    memset(color, -1, sizeof(int) * graphSize);

    for (int i = 0; i < graphSize; i++) {
        if (color[i] == -1) {
            if (!bfs(graph, color, graphSize, graphColSize, i)) {
                free(color);
                return false;
            }
        }
    }

    free(color);
    return true;
}
