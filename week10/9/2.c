#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

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