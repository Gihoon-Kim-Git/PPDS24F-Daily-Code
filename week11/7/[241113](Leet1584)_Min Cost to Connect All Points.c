/*You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Edge {
    int u, v, weight;
} Edge;

typedef struct DisjointSet {
    int *parent, *rank;
    int n;
} DisjointSet;

int compareEdges(const void *a, const void *b) {
    Edge *e1 = (Edge *)a;
    Edge *e2 = (Edge *)b;
    return e1->weight - e2->weight;
}

DisjointSet* createSet(int n) {
    DisjointSet *set = (DisjointSet *)malloc(sizeof(DisjointSet));
    set->parent = (int *)malloc(n * sizeof(int));
    set->rank = (int *)calloc(n, sizeof(int));
    set->n = n;
    for (int i = 0; i < n; i++) {
        set->parent[i] = i;
    }
    return set;
}

int find(DisjointSet *set, int u) {
    if (set->parent[u] != u)
        set->parent[u] = find(set, set->parent[u]);  // Path compression
    return set->parent[u];
}

void unionSet(DisjointSet *set, int u, int v) {
    int root_u = find(set, u);
    int root_v = find(set, v);
    if (root_u != root_v) {
        if (set->rank[root_u] > set->rank[root_v])
            set->parent[root_v] = root_u;
        else if (set->rank[root_u] < set->rank[root_v])
            set->parent[root_u] = root_v;
        else {
            set->parent[root_v] = root_u;
            set->rank[root_u]++;
        }
    }
}

int kruskal_sum(Edge edges[], int n, int e) {  //e가 전체 edge 개수인가보다.
    int sum = 0;

    qsort(edges, e, sizeof(Edge), compareEdges);
    DisjointSet *set = createSet(n);
    //printf("Edges in MST:\n");
    
    for (int i = 0; i < e; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        if (find(set, u) != find(set, v)) {
            //printf("%d - %d: %d\n", u, v, edges[i].weight);
            sum += edges[i].weight;
            unionSet(set, u, v);
        }
    }
    free(set->parent);
    free(set->rank);
    free(set);

    return sum;
}

//절댓값(맨해튼 거리) 계산용으로 만든 함수
Edge make_edge_idx(int i, int j, int** points){
    Edge new_edge;
    int w_x = (points[i][0] - points[j][0]) > 0 ? (points[i][0] - points[j][0]) : -(points[i][0] - points[j][0]);
    int w_y = (points[i][1] - points[j][1]) > 0 ? (points[i][1] - points[j][1]) : -(points[i][1] - points[j][1]);
    
    new_edge.u = i;
    new_edge.v = j;
    new_edge.weight = w_x + w_y;
    return new_edge;
}

int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize) {
    //전체 edge를 저장하는 array
    int num_edges = pointsSize * (pointsSize-1);
    Edge* edge_list = (Edge*)malloc((sizeof(Edge) * num_edges));

    //edge_list에 edge 담기
    int edge_index = 0;
    for (int i = 0; i < pointsSize; i++){
        for (int j = 0; j < pointsSize; j++){
            if (i != j){
                edge_list[edge_index++] = make_edge_idx(i, j, points);
            }
        }
    }

    return kruskal_sum(edge_list, pointsSize, num_edges); 
}