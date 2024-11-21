#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* stack1;
    int* stack2;
    int top1;
    int top2;
    int capacity;
} MyQueue;

MyQueue* myQueueCreate(int capacity) {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->stack1 = (int*)malloc(capacity * sizeof(int));
    queue->stack2 = (int*)malloc(capacity * sizeof(int));
    queue->top1 = -1;
    queue->top2 = -1;
    queue->capacity = capacity;
    return queue;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->stack1[++(obj->top1)] = x;
}

int myQueuePop(MyQueue* obj) {
    if (obj->top2 == -1) {
        while (obj->top1 != -1) {
            obj->stack2[++(obj->top2)] = obj->stack1[(obj->top1)--];
        }
    }
    return obj->stack2[(obj->top2)--];
}

int myQueuePeek(MyQueue* obj) {
    if (obj->top2 == -1) {
        while (obj->top1 != -1) {
            obj->stack2[++(obj->top2)] = obj->stack1[(obj->top1)--];
        }
    }
    return obj->stack2[obj->top2];
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->top1 == -1 && obj->top2 == -1;
}

void myQueueFree(MyQueue* obj) {
    free(obj->stack1);
    free(obj->stack2);
    free(obj);
}

// Example usage
int main() {
    MyQueue* queue = myQueueCreate(100);
    myQueuePush(queue, 1);
    myQueuePush(queue, 2);
    printf("%d\n", myQueuePeek(queue)); // Output: 1
    printf("%d\n", myQueuePop(queue));  // Output: 1
    printf("%d\n", myQueueEmpty(queue));// Output: 0
    myQueueFree(queue);
    return 0;
}
