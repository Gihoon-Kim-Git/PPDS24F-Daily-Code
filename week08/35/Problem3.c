#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *data;
    int front;
    int rear;
    int size;
    int capacity;
} MyCircularDeque;

MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque* obj = (MyCircularDeque*)malloc(sizeof(MyCircularDeque));
    obj->data = (int*)malloc(sizeof(int) * (k + 1));
    obj->front = 0;
    obj->rear = 0;
    obj->size = 0;
    obj->capacity = k + 1;
    return obj;
}

bool myCircularDequeIsFull(MyCircularDeque* obj) {
    return (obj->rear + 1) % obj->capacity == obj->front;
}

bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    return obj->front == obj->rear;
}

bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if (myCircularDequeIsFull(obj)) {
        return false;
    }
    obj->front = (obj->front - 1 + obj->capacity) % obj->capacity;
    obj->data[obj->front] = value;
    return true;
}

bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if (myCircularDequeIsFull(obj)) {
        return false;
    }
    obj->data[obj->rear] = value;
    obj->rear = (obj->rear + 1) % obj->capacity;
    return true;
}

bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) {
        return false;
    }
    obj->front = (obj->front + 1) % obj->capacity;
    return true;
}

bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) {
        return false;
    }
    obj->rear = (obj->rear - 1 + obj->capacity) % obj->capacity;
    return true;
}

int myCircularDequeGetFront(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) {
        return -1;
    }
    return obj->data[obj->front];
}

int myCircularDequeGetRear(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) {
        return -1;
    }
    return obj->data[(obj->rear - 1 + obj->capacity) % obj->capacity];
}

void myCircularDequeFree(MyCircularDeque* obj) {
    free(obj->data);
    free(obj);
}

int main() {
    MyCircularDeque* deque = myCircularDequeCreate(3);
    printf("InsertLast 1: %d\n", myCircularDequeInsertLast(deque, 1));
    printf("InsertLast 2: %d\n", myCircularDequeInsertLast(deque, 2));
    printf("InsertFront 3: %d\n", myCircularDequeInsertFront(deque, 3));
    printf("InsertFront 4 (should be false): %d\n", myCircularDequeInsertFront(deque, 4));
    printf("GetRear: %d\n", myCircularDequeGetRear(deque));
    printf("IsFull: %d\n", myCircularDequeIsFull(deque));
    printf("DeleteLast: %d\n", myCircularDequeDeleteLast(deque));
    printf("InsertFront 4: %d\n", myCircularDequeInsertFront(deque, 4));
    printf("GetFront: %d\n", myCircularDequeGetFront(deque));
    myCircularDequeFree(deque);
    return 0;
}
