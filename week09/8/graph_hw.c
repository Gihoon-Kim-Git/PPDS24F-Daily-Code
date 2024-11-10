#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

// 1. Find if path exists in graph
// 단일 연결 리스트 구조체 정의
typedef struct _slist {
    int *array; // 노드의 이웃을 저장하는 배열
    int len;    // 이웃의 수
} s_list;

// 유효한 경로 검사 함수
bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination) {
    bool ret = false; // 반환값 초기화

    // 매우 희소한 행렬
    // 사용할 메모리 양 계산
    int *counts = calloc(n, sizeof(int)); // 각 노드의 연결 수를 세기 위한 배열
    for (int i = 0; i < edgesSize; i += 1) {
        counts[edges[i][0]] += 1; // 첫 번째 노드의 연결 수 증가
        counts[edges[i][1]] += 1; // 두 번째 노드의 연결 수 증가
    } // for i

    // 주어진 모든 링크를 기록
    s_list *row = calloc(n, sizeof(s_list)); // 각 노드의 연결 리스트를 위한 배열

    // 메모리 할당
    for (int i = 0; i < n; i += 1) {
        row[i].array = malloc(counts[i] * sizeof(int)); // 연결 수에 맞춰 메모리 할당
        row[i].len = 0; // 초기 길이 0으로 설정
    } // for i
    free(counts); // counts 배열 해제
    counts = NULL; // 포인터 초기화

    // 스택 푸시 스타일로 값 쓰기
    for (int i = 0; i < edgesSize; i += 1) {
        row[edges[i][0]].array[row[edges[i][0]].len] = edges[i][1]; // 첫 번째 노드의 이웃에 두 번째 노드 추가
        row[edges[i][0]].len += 1; // 길이 증가

        row[edges[i][1]].array[row[edges[i][1]].len] = edges[i][0]; // 두 번째 노드의 이웃에 첫 번째 노드 추가
        row[edges[i][1]].len += 1; // 길이 증가
    } // for i

    // 깊이 우선 탐색 (DFS)
    char *visited = calloc(n, sizeof(char)); // 방문한 노드를 기록할 배열
    int *stack = calloc(n, sizeof(int)); // 스택 배열
    int stack_top = 0; // 스택의 상단 인덱스 초기화

    stack[stack_top] = source; // 시작 노드를 스택에 추가
    stack_top += 1; // 상단 인덱스 증가
    visited[source] = 1; // 시작 노드 방문 표시
    int current; // 현재 노드 변수

    while (stack_top) { // 스택이 비어있지 않은 동안 반복
        stack_top -= 1; // 상단 인덱스 감소
        current = stack[stack_top]; // 현재 노드를 스택에서 꺼냄

        if (current == destination) { // 현재 노드가 목적지인 경우
            ret = true; // 경로 존재
            break; // 반복 종료
        } // if

        for (int i = 0; i < row[current].len; i += 1) { // 현재 노드의 모든 이웃에 대해 반복
            if (!visited[row[current].array[i]]) { // 이웃 노드가 방문되지 않은 경우
                stack[stack_top] = row[current].array[i]; // 이웃 노드를 스택에 추가
                stack_top += 1; // 상단 인덱스 증가
                visited[row[current].array[i]] = 1; // 이웃 노드 방문 표시
            } // if
        } // for i
    } // while

    // 메모리 정리
    for (int i = 0; i < n; i += 1) {
        free(row[i].array); // 각 노드의 이웃 배열 해제
        row[i].array = NULL; // 포인터 초기화
    } // for i

    free(row); // row 배열 해제
    free(visited); // visited 배열 해제
    row = NULL; // 포인터 초기화
    visited = NULL; // 포인터 초기화
    free(stack); // stack 배열 해제
    stack = NULL; // 포인터 초기화

    return ret; // 결과 반환
}


//2. Is graph bipartite?
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 큐를 위한 구조체 정의
typedef struct {
    int *data;
    int front;
    int rear;
    int capacity;
} Queue;

// 큐 초기화 함수
Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->data = (int*)malloc(sizeof(int) * capacity);
    queue->front = 0;
    queue->rear = 0;
    queue->capacity = capacity;
    return queue;
}

// 큐가 비었는지 확인하는 함수
bool isEmpty(Queue* queue) {
    return queue->front == queue->rear;
}

// 큐에 원소 추가하는 함수
void enqueue(Queue* queue, int value) {
    queue->data[queue->rear++] = value;
}

// 큐에서 원소 꺼내는 함수
int dequeue(Queue* queue) {
    return queue->data[queue->front++];
}

// 큐 메모리 해제 함수
void freeQueue(Queue* queue) {
    free(queue->data);
    free(queue);
}

bool isBipartite(int** graph, int graphSize, int* graphColSize) {
    int* color = (int*)malloc(sizeof(int) * graphSize);
    for (int i = 0; i < graphSize; i++) color[i] = -1; // 색 초기화

    // 모든 노드를 검사
    for (int i = 0; i < graphSize; i++) {
        if (color[i] != -1) continue; // 이미 색칠된 노드는 건너뜀

        // 큐 생성 및 BFS 초기화
        Queue* queue = createQueue(graphSize);
        enqueue(queue, i);
        color[i] = 0; // 시작 노드를 0으로 색칠

        // BFS 시작
        while (!isEmpty(queue)) {
            int node = dequeue(queue);

            // 현재 노드의 인접 노드를 모두 검사
            for (int j = 0; j < graphColSize[node]; j++) {
                int neighbor = graph[node][j];

                // 인접 노드가 아직 색칠되지 않은 경우
                if (color[neighbor] == -1) {
                    color[neighbor] = 1 - color[node]; // 다른 색으로 색칠
                    enqueue(queue, neighbor);
                }
                // 인접 노드가 현재 노드와 같은 색이면 이분 그래프가 아님
                else if (color[neighbor] == color[node]) {
                    free(color);
                    freeQueue(queue);
                    return false;
                }
            }
        }
        freeQueue(queue); // 각 연결 요소의 BFS가 끝난 후 큐 메모리 해제
    }
    free(color); // 색깔 배열 메모리 해제
    return true;
}
 


//3. maximum depth of n-aray tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int compare(void const *a, void const *b) {
    return *(int *)a - *(int *)b;
}

int num_node(struct TreeNode* root, int len) {
    if (root == NULL) return 0;

    return 1 + num_node(root->left, len) + num_node(root->right, len);
}

void kthSmallest_helper(struct TreeNode* root, int* arr, int* idx) {
    if (root == NULL) return;
    arr[*idx] = root->val;
    (*idx)++;

    kthSmallest_helper(root->left, arr, idx);
    kthSmallest_helper(root->right, arr, idx);
}

int kthSmallest(struct TreeNode* root, int k) {
    int len = 0;
    int num = num_node(root, len);
    
    int* arr = (int*)malloc(sizeof(int)*num);
    int idx = 0;

    kthSmallest_helper(root, arr, &idx);

    qsort(arr, num, sizeof(int), compare);
    
    return arr[k-1];
}



//4. max profit
/*
An array A consisting of N integers is given. It contains daily prices of a stock share for a period of N consecutive days. If a single share was bought on day P and sold on day Q, where 0 ≤ P ≤ Q < N, then the profit of such transaction is equal to A[Q] − A[P], provided that A[Q] ≥ A[P]. Otherwise, the transaction brings loss of A[P] − A[Q].

For example, consider the following array A consisting of six elements such that:

  A[0] = 23171
  A[1] = 21011
  A[2] = 21123
  A[3] = 21366
  A[4] = 21013
  A[5] = 21367
If a share was bought on day 0 and sold on day 2, a loss of 2048 would occur because A[2] − A[0] = 21123 − 23171 = −2048. If a share was bought on day 4 and sold on day 5, a profit of 354 would occur because A[5] − A[4] = 21367 − 21013 = 354. Maximum possible profit was 356. It would occur if a share was bought on day 1 and sold on day 5.

Write a function,

int solution(int A[], int N);

that, given an array A consisting of N integers containing daily prices of a stock share for a period of N consecutive days, returns the maximum possible profit from one transaction during this period. The function should return 0 if it was impossible to gain any profit.

For example, given array A consisting of six elements such that:

  A[0] = 23171
  A[1] = 21011
  A[2] = 21123
  A[3] = 21366
  A[4] = 21013
  A[5] = 21367
the function should return 356, as explained above.
*/
#define max(X, Y) (X) > (Y)? (X):(Y)

int solution(int A[], int N) {
    int* arr = (int*)malloc(sizeof(int)*N);
    // int dp[N][2];
    // dp[0][0] = 0;
    // dp[0][1] = -A[0];
    int left = 0;
    int right = N-1;

    int i = 0;
    int max_num = 0;
    while (left < right) {
        if (A[right] > A[left]) {
            arr[i] = A[right] - A[left];
            left++;
            
        }

        else {
            left++;
        }
        i++;

    }
}


//5. kth smallest element in bst

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int compare(void const *a, void const *b) {
    return *(int *)a - *(int *)b;
}

int num_node(struct TreeNode* root, int len) {
    if (root == NULL) return 0;

    return 1 + num_node(root->left, len) + num_node(root->right, len);
}

void kthSmallest_helper(struct TreeNode* root, int* arr, int* idx) {
    if (root == NULL) return;
    arr[*idx] = root->val;
    (*idx)++;

    kthSmallest_helper(root->left, arr, idx);
    kthSmallest_helper(root->right, arr, idx);
}

int kthSmallest(struct TreeNode* root, int k) {
    int len = 0;
    int num = num_node(root, len);
    
    int* arr = (int*)malloc(sizeof(int)*num);
    int idx = 0;

    kthSmallest_helper(root, arr, &idx);

    qsort(arr, num, sizeof(int), compare);
    
    return arr[k-1];
}