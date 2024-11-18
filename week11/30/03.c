#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int min(int x, int y) {
    return (x >= y) ? y : x; 
}

// 맨해튼 거리 계산 함수
int calDist(int* p1, int* p2) {
    return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
}

// 프림 알고리즘을 사용하여 최소 비용을 구하는 함수
int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize) {
    int* minCost = (int*)malloc(sizeof(int) * pointsSize); // 각 점까지 연결된 최소 비용
    bool* visited = (bool*)malloc(sizeof(bool) * pointsSize); // 방문 여부
    int totalCost = 0;
    
    // 초기화
    for (int i = 0; i < pointsSize; i++) {
        minCost[i] = INT_MAX; // 최소 비용은 무한으로 초기화
        visited[i] = false;   // 방문하지 않은 점
    }
    
    minCost[0] = 0; // 시작점은 0에서 시작
    
    for (int count = 0; count < pointsSize; count++) {
        int u = -1;
        int minEdge = INT_MAX;

        // 현재까지 방문하지 않은 점 중에서 가장 최소 비용의 점을 찾음
        for (int i = 0; i < pointsSize; i++) {
            if (!visited[i] && minCost[i] < minEdge) {
                minEdge = minCost[i];
                u = i;
            }
        }

        // 만약 더 이상 연결할 점이 없다면 종료
        if (u == -1) {
            break;
        }

        // 방문 처리
        visited[u] = true;
        totalCost += minEdge;

        // 연결된 점들을 갱신
        for (int v = 0; v < pointsSize; v++) {
            if (!visited[v]) {
                int dist = calDist(points[u], points[v]);
                minCost[v] = min(minCost[v], dist);
            }
        }
    }

    free(minCost);
    free(visited);

    return totalCost;
}

int main() {
    int points1[][2] = {{0,0}, {2,2}, {3,10}, {5,2}, {7,0}};
    int pointsSize = 5;
    int* pointsColSize = (int*)malloc(pointsSize * sizeof(int));
    
    for (int i = 0; i < pointsSize; i++) {
        pointsColSize[i] = 2;  // 각 점은 2개의 좌표를 가지고 있음
    }

    // 2D 배열로 전달하기 위해 포인터 배열로 변환
    int** points = (int**)malloc(pointsSize * sizeof(int*));
    for (int i = 0; i < pointsSize; i++) {
        points[i] = points1[i];
    }

    printf("minimum Cost to Connect All Points: %d\n", minCostConnectPoints(points, pointsSize, pointsColSize));

    free(pointsColSize);
    free(points);

    return 0;
}