#include <stdio.h>
#include <stdlib.h>

/*
 * Problem Description:
 * --------------------
 * You are given an array points representing integer coordinates of some points on a 2D-plane,
 * where points[i] = [xi, yi].
 *
 * The cost of connecting two points [xi, yi] and [xj, yj] is the Manhattan distance between them:
 * |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.
 *
 * Return the minimum cost to make all points connected. All points are connected if there is exactly
 * one simple path between any two points.
 *
 * Example:
 * --------
 * Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
 * Output: 20
 *
 * Constraints:
 * ------------
 * 1 <= points.length <= 1000
 * -10^6 <= xi, yi <= 10^6
 * All pairs (xi, yi) are distinct.
 */

// edge structure
typedef struct {
    int x, y, cost;
} Edge;

int manhattan_distance(int* point_i, int* point_j) {
    return abs(point_i[0] - point_j[0]) + abs(point_i[1] - point_j[1]);
}

// find function with path compression
int find_set(int* parent_set, int x) {
    if (parent_set[x] != x) {
        parent_set[x] = find_set(parent_set, parent_set[x]);
    }
    return parent_set[x];
}

// union function with union by mst rank
void union_set(int* parent_set, int* rank, int x, int y) {
    int root_x = find_set(parent_set, x);
    int root_y = find_set(parent_set, y);

    if (root_x != root_y) {
        if (rank[root_x] > rank[root_y]) {
            parent_set[root_y] = root_x;
        } else if (rank[root_x] < rank[root_y]) {
            parent_set[root_x] = root_y;
        } else {
            parent_set[root_y] = root_x;
            rank[root_x]++;
        }
    }
}

// [GPT] comparator function for qsort to sort edges by cost
int compare(const void* a, const void* b) {
    return ((Edge*)a)->cost - ((Edge*)b)->cost;
}

int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize) {

    // create a single list of edges (G.E)
    int totalEdges = pointsSize * (pointsSize - 1) / 2;
    Edge* edges = (Edge*)malloc(totalEdges * sizeof(Edge));

    int k = 0;
    for (int i = 0; i < pointsSize; ++i) {
        for (int j = i + 1; j < pointsSize; ++j) {
            edges[k].x = i;
            edges[k].y = j;
            edges[k].cost = manhattan_distance(points[i], points[j]);
            k++;
        }
    }

    // sort the list of edges into monotonically increasing order by weight
    // [GPT] qsort
    qsort(edges, totalEdges, sizeof(Edge), compare);

    int min_cost = 0;
    int* mst_parent_set = (int*)malloc(pointsSize * sizeof(int));
    int* mst_rank = (int*)malloc(pointsSize * sizeof(int));

    for (int i = 0; i < pointsSize; ++i) {
        mst_parent_set[i] = i;
        mst_rank[i] = 0;
    }

    int edges_used = 0;

    for (int i = 0; i < totalEdges; ++i) { // for each edge from the sorted list in order

        // MST complete check!
        if (edges_used == pointsSize - 1) {
            break;
        }

        int u = edges[i].x;
        int v = edges[i].y;
        int edge_cost = edges[i].cost;

        if (find_set(mst_parent_set, u) != find_set(mst_parent_set, v)) {
            // add the next edge unless doing so would create a cycle
            min_cost += edge_cost;
            union_set(mst_parent_set, mst_rank, u, v);
            edges_used++;
        }
    }

    // memory clean up
    free(edges);
    free(mst_parent_set);
    free(mst_rank);

    return min_cost;
}