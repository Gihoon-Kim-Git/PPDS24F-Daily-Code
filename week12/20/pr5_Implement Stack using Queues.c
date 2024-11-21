#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 큐 구조체 정의
typedef struct {
    int* data;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

// 스택 구조체 정의
typedef struct {
    Queue* q1; // 주 큐
    Queue* q2; // 보조 큐
} MyStack;

// 큐 생성 함수
Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->data = (int*)malloc(sizeof(int) * capacity);
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    queue->capacity = capacity;
    return queue;
}

// 큐 삭제 함수
void freeQueue(Queue* queue) {
    free(queue->data);
    free(queue);
}

// 큐가 비었는지 확인
bool isEmptyQueue(Queue* queue) {
    return queue->size == 0;
}

// 큐에 삽입
void enqueue(Queue* queue, int value) {
    if (queue->size == queue->capacity) return; // 큐가 가득 찼음
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->data[queue->rear] = value;
    queue->size++;
}

// 큐에서 삭제
int dequeue(Queue* queue) {
    if (isEmptyQueue(queue)) return -1; // 큐가 비었음
    int value = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return value;
}

// 큐의 앞쪽 값 반환
int frontQueue(Queue* queue) {
    if (isEmptyQueue(queue)) return -1; // 큐가 비었음
    return queue->data[queue->front];
}

// 스택 생성
MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    stack->q1 = createQueue(100); // 최대 100 요소
    stack->q2 = createQueue(100);
    return stack;
}

// 스택에 값 푸시
void myStackPush(MyStack* obj, int x) {
    enqueue(obj->q2, x); // q2에 값 삽입

    // q1의 모든 요소를 q2로 이동
    while (!isEmptyQueue(obj->q1)) {
        enqueue(obj->q2, dequeue(obj->q1));
    }

    // q1과 q2를 스왑
    Queue* temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;
}

// 스택에서 팝
int myStackPop(MyStack* obj) {
    return dequeue(obj->q1);
}

// 스택의 최상단 값 반환
int myStackTop(MyStack* obj) {
    return frontQueue(obj->q1);
}

// 스택이 비었는지 확인
bool myStackEmpty(MyStack* obj) {
    return isEmptyQueue(obj->q1);
}

// 스택 메모리 해제
void myStackFree(MyStack* obj) {
    freeQueue(obj->q1);
    freeQueue(obj->q2);
    free(obj);
}

/**
 * 사용 예시:
int main() {
    MyStack* stack = myStackCreate();
    myStackPush(stack, 1);
    myStackPush(stack, 2);
    myStackPush(stack, 3);

    printf("Top: %d\n", myStackTop(stack)); // 출력: 3
    printf("Pop: %d\n", myStackPop(stack)); // 출력: 3
    printf("Empty: %d\n", myStackEmpty(stack)); // 출력: 0 (false)

    myStackFree(stack);
    return 0;
}
 */
