#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 50

typedef struct {
    int start_idx;
    int end_idx;
    int size;
    int capacity;
    int arr[MAX];
} MyCircularDeque;

MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque* myQ = (MyCircularDeque*)malloc(sizeof(MyCircularDeque));
    myQ->capacity = k;
    myQ->size = 0;
    myQ->start_idx = 0;
    myQ->end_idx = -1;
    return myQ;
}

bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if (myCircularDequeIsFull(obj)) return false;

    obj->start_idx = (obj->start_idx - 1 + obj->capacity) % obj->capacity;
    obj->arr[obj->start_idx] = value;
    obj->size++;
    return true;
}

bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if (myCircularDequeIsFull(obj)) return false;

    obj->end_idx = (obj->end_idx + 1) % obj->capacity;
    obj->arr[obj->end_idx] = value;
    obj->size++;
    return true;
}

bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) return false;

    obj->start_idx = (obj->start_idx + 1) % obj->capacity;
    obj->size--;
    return true;
}

bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) return false;

    obj->end_idx = (obj->end_idx - 1 + obj->capacity) % obj->capacity;
    obj->size--;
    return true;
}

int myCircularDequeGetFront(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) return -1;
    return obj->arr[obj->start_idx];
}

int myCircularDequeGetRear(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) return -1;
    return obj->arr[obj->end_idx];
}

bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    return obj->size == 0;
}

bool myCircularDequeIsFull(MyCircularDeque* obj) {
    return obj->size == obj->capacity;
}

void myCircularDequeFree(MyCircularDeque* obj) {
    free(obj);
}

int main() {
    // Circular Deque 예시
    MyCircularDeque* deque = myCircularDequeCreate(5);

    myCircularDequeInsertLast(deque, 10);
    myCircularDequeInsertLast(deque, 20);
    myCircularDequeInsertFront(deque, 5);

    printf("Front: %d\n", myCircularDequeGetFront(deque));
    printf("Rear: %d\n", myCircularDequeGetRear(deque));  

    myCircularDequeDeleteFront(deque);
    printf("Front after delete: %d\n", myCircularDequeGetFront(deque)); 

    myCircularDequeFree(deque);
    return 0;
}
