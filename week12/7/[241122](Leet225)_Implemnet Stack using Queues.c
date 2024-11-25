/*
Constraints:
    1 <= x <= 9
    At most 100 calls will be made to push, pop, top, and empty.
    All the calls to pop and top are valid.
 */

//Using 2 Queues

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int* data;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

// 큐 생성
Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->data = (int*)malloc(capacity * sizeof(int));
    queue->front = 0;
    queue->rear = 0;
    queue->size = 0;
    queue->capacity = capacity;
    return queue;
}

// 큐 연산
bool isEmpty(Queue* queue) {
    return queue->size == 0;
}

void enqueue(Queue* queue, int value) {
    if (queue->size == queue->capacity) return; // 용량 초과 방지
    queue->data[queue->rear] = value;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->size++;
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) return -1; // 비어있을 때
    int value = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return value;
}

int front(Queue* queue) {
    return queue->data[queue->front];
}

// 큐 메모리 해제
void freeQueue(Queue* queue) {
    free(queue->data);
    free(queue);
}



typedef struct {
    Queue* primaryQueue;
    Queue* secondaryQueue;
} MyStack;


MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    stack->primaryQueue = createQueue(MAX_SIZE);
    stack->secondaryQueue = createQueue(MAX_SIZE);
    return stack;
}

void myStackPush(MyStack* obj, int x) {
    enqueue(obj->secondaryQueue, x);

    // primaryQueue의 모든 요소를 secondaryQueue로 이동
    while (!isEmpty(obj->primaryQueue)) {
        enqueue(obj->secondaryQueue, dequeue(obj->primaryQueue));
    }

    // primaryQueue와 secondaryQueue를 교환
    Queue* temp = obj->primaryQueue;
    obj->primaryQueue = obj->secondaryQueue;
    obj->secondaryQueue = temp;
}

int myStackPop(MyStack* obj) {
    return dequeue(obj->primaryQueue);
}

int myStackTop(MyStack* obj) {
    return front(obj->primaryQueue);
}

bool myStackEmpty(MyStack* obj) {
    return isEmpty(obj->primaryQueue);
}

void myStackFree(MyStack* obj) {
    freeQueue(obj->primaryQueue);
    freeQueue(obj->secondaryQueue);
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 * int param_2 = myStackPop(obj);
 * int param_3 = myStackTop(obj);
 * bool param_4 = myStackEmpty(obj);
 * myStackFree(obj);
*/


// Using 1 queue---------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* data;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

// 큐 생성
Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->data = (int*)malloc(capacity * sizeof(int));
    queue->front = 0;
    queue->rear = 0;
    queue->size = 0;
    queue->capacity = capacity;
    return queue;
}

// 큐 연산
bool isEmpty(Queue* queue) {
    return queue->size == 0;
}

void enqueue(Queue* queue, int value) {
    if (queue->size == queue->capacity) return; // 용량 초과 방지
    queue->data[queue->rear] = value;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->size++;
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) return -1; // 비어있을 때
    int value = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return value;
}

int front(Queue* queue) {
    return queue->data[queue->front];
}

// 큐 메모리 해제
void freeQueue(Queue* queue) {
    free(queue->data);
    free(queue);
}

// MyStack 구조체 정의
typedef struct {
    Queue* queue;
} MyStack;

// MyStack 생성
MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    stack->queue = createQueue(100); // 초기 용량 설정
    return stack;
}

// 스택 연산
void myStackPush(MyStack* obj, int x) {
    enqueue(obj->queue, x);
    int size = obj->queue->size;

    // 새로 삽입된 요소를 앞부분으로 이동
    for (int i = 0; i < size - 1; i++) {
        enqueue(obj->queue, dequeue(obj->queue));
    }
}

int myStackPop(MyStack* obj) {
    return dequeue(obj->queue);
}

int myStackTop(MyStack* obj) {
    return front(obj->queue);
}

bool myStackEmpty(MyStack* obj) {
    return isEmpty(obj->queue);
}

void myStackFree(MyStack* obj) {
    freeQueue(obj->queue);
    free(obj);
}