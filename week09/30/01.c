// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include <limits.h>

// /*
// _________[ 전 략 ]_________
// 1. dfs를 돌려서 
// 2. destination을 방문했으면 true를 뱉자.
// -> 문제
// edgeList -> adjMatrix로 변환해서 했더니 메모리 초과가 나오네...
// -> 해결
// edgeList -> adjMatrix -> adjList로 바꿔서 해보자. 
// */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int** edgeList_to_adjList(int** edges, int n, int edgesSize, int* neiCntArr) {
    // (1) 각 노드의 인접 노드 개수를 세기
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        neiCntArr[u]++;
        neiCntArr[v]++;
    }

    // (2) 인접 리스트의 메모리 할당
    int** adjList = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        adjList[i] = (int*)malloc(neiCntArr[i] * sizeof(int));
        neiCntArr[i] = 0;  // 인덱스를 0으로 초기화하여 나중에 사용할 때 사용
    }

    // (3) 엣지를 통해 인접 리스트 구성
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u][neiCntArr[u]++] = v;
        adjList[v][neiCntArr[v]++] = u;
    }

    return adjList;
}

int* dfs_graph_adjList(int** adjList, int* neiCntArr, int v, int* visited) {
    if (visited[v] == 1) {
        return visited;
    }
    visited[v] = 1;

    for (int j = 0; j < neiCntArr[v]; j++) {
        int u = adjList[v][j];
        if (visited[u] == 0) {
            dfs_graph_adjList(adjList, neiCntArr, u, visited);
        }
    }
    return visited;
}

bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination) {
    int* visitLog = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        visitLog[i] = 0;
    }

    int* neiCntArr = (int*)calloc(n, sizeof(int));  // 각 노드의 인접 노드 개수를 저장할 배열
    int** adjList = edgeList_to_adjList(edges, n, edgesSize, neiCntArr);

    dfs_graph_adjList(adjList, neiCntArr, source, visitLog);

    bool result = (visitLog[destination] == 1);

    free(visitLog);
    free(neiCntArr);
    for (int i = 0; i < n; i++) {
        free(adjList[i]);
    }
    free(adjList);

    return result;
}



// //_________SUPPORT 함수들__________//
// int** edgeList_to_adjMatrix(int** edges, int n, int edgesSize) {
//     int** adjMatrix = (int**)malloc(n * sizeof(int*));
//     for (int i = 0; i < n; i ++) {
//         adjMatrix[i] = (int*)malloc(n * sizeof(int));
//         for (int k = 0; k < n; k++) {
//             adjMatrix[i][k] = 0; //초기화 연결 안됐음을 알려쥼
//         } 
//     }
//     //bipartite 양방향연결이라고 생각
//     for (int j = 0; j < edgesSize; j++) {
//         int u = edges[j][0];
//         int v = edges[j][1];
//         adjMatrix[u][v] = 1; 
//         adjMatrix[v][u] = 1;
//     }

//     return adjMatrix;
// }
// int** adjMatrix_to_adjList(int** adjMatrix, int n, int** edges, int edgesSize) {

//     // (1) 노드별 인접 노드 개수를 세고 배열을 할당
//     int* neiCntArr = (int*)malloc(n * sizeof(int));
//     int* neiCntIndex = (int*)malloc(n * sizeof(int));
//     for (int i = 0; i < n; i++) {
//         int neiCnt_i = 0;
//         for (int j = 0; j < n; j++) {
//             if (adjMatrix[i][j] == 1) {
//                 neiCnt_i++;
//             }
//         }
//         neiCntArr[i] = neiCnt_i;
//         neiCntIndex[i] = 0;
//     }

//     // (2) 인접 리스트를 위해 메모리 할당
//     int** adjList = (int**)malloc(n * sizeof(int*));
//     for (int i = 0; i < n; i++) {
//         adjList[i] = (int*)malloc(neiCntArr[i] * sizeof(int));
//     }

//     // (3) 엣지를 통해 인접 리스트 구성
//     for (int e = 0; e < edgesSize; e++) {
//         int u = edges[e][0];
//         int v = edges[e][1];
//         adjList[u][neiCntIndex[u]++] = v;
//         adjList[v][neiCntIndex[v]++] = u;
//     }

//     // (4) 결과 출력
//     // for (int i = 0; i < n; i++) {
//     //     printf("Node %d: ", i);
//     //     for (int k = 0; k < neiCntArr[i]; k++) {
//     //         printf("%d ", adjList[i][k]);
//     //     }
//     //     printf("\n");
//     // }

//     // 메모리 해제
//     free(neiCntArr);
//     free(neiCntIndex);

//     return adjList;
// }


// void print_adjMatrix(int** adjMatrix, int n) {
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             printf("%d ", adjMatrix[i][j]);
//         }
//         printf("\n");
//     }
// }

// void print_edgeList(int** edges, int edgesSize, int* edgesColSize){
//     for (int i = 0; i < edgesSize; i ++) {
//         printf("[");
//         for (int j = 0; j < edgesColSize[i]; j++) {
//             printf(" %d", edges[i][j]);
//         }
//         printf(" ]");
//     }
//     printf("\n");
// }


// //___________MAIN 함수들____________//
// int* dfs_graph_adjList(int** adjList, int n, int v, int* visited){
//     // v를 방문해봅시다
//     // (1). 끝내기: v가 존재하지 않거나나, 이미 방문한거면 
//     if (visited[v] == 1) {
//         return visited;
//     } 
//     // (2). 진행하기: v를 방문했으니 visit 체크하고
//     // printf("%d->", v);
//     visited[v]=1;
//     // (3). v랑 연결된 모든 애들에 대해
//     //     -> 아직 방문안했으면 -> 재귀호출
//     int neiN = sizeof(adjList[v])/sizeof(int);
//     for (int j = 0; j < neiN; j++) {
//         int u = adjList[v][j];
//         if (visited[u] == 0) {
//             dfs_graph_adjList(adjList, n, u, visited);
//     }
//     }
//     // printf("END\n");
//     return visited;
// }

// int* dfs_graph_adjMatrix(int** adjMatrix, int n, int v, int* visited){
//     // v를 방문해봅시다
//     // (1). 끝내기: v가 존재하지 않거나나, 이미 방문한거면 
//     if (visited[v] == 1) {
//         return visited;
//     } 
//     // (2). 진행하기: v를 방문했으니 visit 체크하고
//     printf("%d->", v);
//     visited[v]=1;
//     // (3). v랑 연결된 모든 애들에 대해
//     //     -> 아직 방문안했으면 -> 재귀호출
//     for (int i =0; i < n; i++) {
//         if (adjMatrix[v][i] == 1) {
//             int u = i;
//             if (visited[u] == 0) {
//                 dfs_graph_adjMatrix(adjMatrix, n, u, visited);
//         }

//         }
//     }
//     printf("END\n");
//     return visited;
// }

// bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination) {
// //dfs든 bfs든해서 destination이 나오면 true 출력. 끝까지했는데 안나오면 false출력
// //(1). dfs 준비하기
//     //(1.1) visited를 만들자
//     int* visitLog = (int*)malloc(n * sizeof(int));
//     for (int i = 0; i < n; i ++) {
//         visitLog[i] = 0;
//     }

//     //(1.2) adjMatrix로 바꾸기
//     int** adjMatrix = edgeList_to_adjMatrix(edges, n, edgesSize);
//     int** adjList = adjMatrix_to_adjList(adjMatrix, n, edges, edgesSize);
    
// //(2) start node에서 dfs 돌리기
//     // dfs_graph_adjMatrix(adjMatrix, n, source, visitLog);
//     dfs_graph_adjList(adjList, n, source, visitLog);

// //(3) destination의 visitLog가 1인지 확인
//     if (visitLog[destination] == 1) {
//         return true;
//     } else {
//         return false;
//     }
// }







// int main() {


// //CASE 1
//     int N = 3;
//     int numEdges = 3;

//     int* myColSize = (int*)malloc(numEdges * sizeof(int));
//     for (int i = 0; i < numEdges; i ++) {
//         myColSize[i] = 2;
//     }
//     int** myEdges = (int**)malloc(numEdges * sizeof(int*)); 
//     for (int i = 0; i < numEdges; i++) {
//         myEdges[i] = (int*)malloc(myColSize[i] * sizeof(int));
//     }
//     myEdges[0][0] = 0;
//     myEdges[1][0] = 1;
//     myEdges[2][0] = 2;
//     myEdges[0][1] = 1;
//     myEdges[1][1] = 2;
//     myEdges[2][1] = 0;

//     int S = 0;
//     int D = 2;
//     // print_edgeList(myEdges, 3, myColSize);
//     // int** myAdjMatrix = edgeList_to_adjMatrix(myEdges, N, numEdges);
//     // int** myAdjList = adjMatrix_to_adjList(myAdjMatrix, N, myEdges, numEdges);
//     // print_adjMatrix(myAdjMatrix, N);
    
//     printf("%d", validPath(N, myEdges, numEdges, myColSize, S, D));


// //___________________ 뒷처리__________________//
//     for (int i = 0; i < numEdges; i++) {
//         free(myEdges[i]);
//     }
//     free(myEdges);
//     free(myColSize);
//     // for (int i = 0; i < N; i++) {
//     //     free(myAdjMatrix[i]);
//     // }
//     // free(myAdjMatrix);


//     return 0;
// }