#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* data;
    int front, rear, size, capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->size = 0;
    queue->rear = capacity - 1;
    queue->data = (int*)malloc(capacity * sizeof(int));
    return queue;
}

bool isEmpty(Queue* queue) {
    return queue->size == 0;
}

void enqueue(Queue* queue, int item) {
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->data[queue->rear] = item;
    queue->size++;
}

int dequeue(Queue* queue) {
    int item = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

typedef struct {
    Queue* queue1;
    Queue* queue2;
} MyStack;

MyStack* myStackCreate(int capacity) {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    stack->queue1 = createQueue(capacity);
    stack->queue2 = createQueue(capacity);
    return stack;
}

void myStackPush(MyStack* obj, int x) {
    enqueue(obj->queue1, x);
}

int myStackPop(MyStack* obj) {
    while (obj->queue1->size > 1) {
        enqueue(obj->queue2, dequeue(obj->queue1));
    }
    int top = dequeue(obj->queue1);
    Queue* temp = obj->queue1;
    obj->queue1 = obj->queue2;
    obj->queue2 = temp;
    return top;
}

int myStackTop(MyStack* obj) {
    while (obj->queue1->size > 1) {
        enqueue(obj->queue2, dequeue(obj->queue1));
    }
    int top = dequeue(obj->queue1);
    enqueue(obj->queue2, top);
    Queue* temp = obj->queue1;
    obj->queue1 = obj->queue2;
    obj->queue2 = temp;
    return top;
}

bool myStackEmpty(MyStack* obj) {
    return isEmpty(obj->queue1);
}

void myStackFree(MyStack* obj) {
    free(obj->queue1->data);
    free(obj->queue2->data);
    free(obj->queue1);
    free(obj->queue2);
    free(obj);
}

// Example usage
int main() {
    MyStack* stack = myStackCreate(100);
    myStackPush(stack, 1);
    myStackPush(stack, 2);
    printf("%d\n", myStackTop(stack));   // Output: 2
    printf("%d\n", myStackPop(stack));   // Output: 2
    printf("%d\n", myStackEmpty(stack)); // Output: 0
    myStackFree(stack);
    return 0;
}
