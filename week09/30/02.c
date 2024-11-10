#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 👑나의 전략👑
// 1. node의 color list 초기화 (0: not yet assigned, -1: black, 1:red)
// 2. node 0번부터 차례로 인접한건 다른 색으로 칠함. 1을 넣어야되는데 0이있거나 그 반대면 false return
// 3. 다 돌았는데 괜찮으면 true return 

bool dfs_color(int** graph, int* graphColSize, int assignedColor, int new, int* colorArr, int* visited) {
    //[1] 방문하고 해야할 일들 하기
    if (colorArr[new] != 0) {
        // 이미 색깔이 있는 경우, 일관성 체크
        return colorArr[new] == assignedColor;
    }

    // 아직 색깔이 배정되지 않은 경우
    colorArr[new] = assignedColor;
    visited[new] = 1;

    //[2] 다음 방문 
    for (int i = 0; i < graphColSize[new]; i++) {
        int nei = graph[new][i];
        if (!dfs_color(graph, graphColSize, -assignedColor, nei, colorArr, visited)) {
            return false;
        }
    }
    return true;
}


bool isBipartite(int** graph, int graphSize, int* graphColSize) {
// 1. node의 color list 초기화 (0: not yet assigned,-1: black, 1:red)
    int* colorArr = (int*)malloc(graphSize * sizeof(int));
    for (int i = 0; i < graphSize; i++) {
        colorArr[i] = 0; 
    }

// 2. node 0번부터 차례로 인접한건 다른 색으로 칠함. 1을 넣어야되는데 0이있거나 그 반대면 false return
    int* visited = (int*)malloc(graphSize * sizeof(int));
    for (int i = 0; i < graphSize; i++) {
        visited[i] = 0; 
    }
    for (int i = 0; i < graphSize; i++) {
        if (visited[i] == 0) {
            if (!dfs_color(graph, graphColSize, 1, i, colorArr, visited)) {
                return false;
            }
        }

    }
// 3. 다 돌았는데 괜찮으면 true return 
    free(colorArr); free(visited);
    return true;

}

int main() {

//CASE 1
    int numN = 4;
    int** adjNodes = (int**)malloc(numN * sizeof(int*));
    int* neiNums = (int*)malloc(numN * sizeof(int));
    neiNums[0] = 3; neiNums[1] = 2; neiNums[2] = 3; neiNums[3] = 2;
    for (int i = 0; i < numN; i++) {
        adjNodes[i] = (int*)malloc(neiNums[i] * sizeof(int));
    }
    adjNodes[0][0] = 1; adjNodes[0][1] = 2; adjNodes[0][2] = 3;
    adjNodes[1][0] = 0; adjNodes[1][1] = 2; 
    adjNodes[2][0] = 0; adjNodes[2][1] = 1; adjNodes[2][2] = 3;
    adjNodes[3][0] = 0; adjNodes[3][1] = 2; 

    printf("%d\n", isBipartite(adjNodes, numN, neiNums));

// CASE 2
    int numN2 = 4;
    int** adjNodes2 = (int**)malloc(numN2 * sizeof(int*));
    int* neiNums2 = (int*)malloc(numN2 * sizeof(int));
    neiNums2[0] = 2; neiNums2[1] = 2; neiNums2[2] = 2; neiNums2[3] = 2;
    for (int i = 0; i < numN2; i++) {
        adjNodes2[i] = (int*)malloc(neiNums2[i] * sizeof(int));
    }
    adjNodes2[0][0] = 1; adjNodes2[0][1] = 3; 
    adjNodes2[1][0] = 0; adjNodes2[1][1] = 2; 
    adjNodes2[2][0] = 1; adjNodes2[2][1] = 3; 
    adjNodes2[3][0] = 0; adjNodes2[3][1] = 2; 
    printf("%d", isBipartite(adjNodes2, numN2, neiNums2));

    return 0;
}