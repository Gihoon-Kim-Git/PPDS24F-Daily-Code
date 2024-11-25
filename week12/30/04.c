#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// First in First Out! 앞에서부터 빼라! 
#define MAX 100

typedef struct {
    int front; int back;
    int capacity;
    int* arr;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* myQ = (MyQueue*)malloc(sizeof(MyQueue));
    myQ->capacity = MAX;
    int* myArr = (int*)malloc(MAX * sizeof(int));
    myQ->arr = myArr;
    myQ->front = 0;
    myQ->back = 0;

    return myQ;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->arr[obj->back] = x;
    obj->back++;
}

int myQueuePop(MyQueue* obj) {
    int ele = obj->arr[obj->front];
    obj->front++;
    return ele;
}

int myQueuePeek(MyQueue* obj) {
    return obj->arr[obj->front];
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->front==obj->back;
}

void myQueueFree(MyQueue* obj) {
    free(obj->arr);
    free(obj);
}
void myQueuePrint(MyQueue* obj) {
    for (int i = obj->front; i < obj->back; i++) { printf("%d ", obj->arr[i]);}
    printf('\n');
}


int main() {
    MyQueue* obj = myQueueCreate();
    printf("Is it Empty?: %s\n", myQueueEmpty(obj) == true ? "true": "false");

    myQueuePush(obj, 1);
    myQueuePush(obj, 3);
    myQueuePush(obj, 5);

    myQueuePrint(obj);

    printf("Popped: %d\n", myQueuePop(obj));
    printf("Peak: %d\n", myQueuePeek(obj));
    myQueuePrint(obj);

    myQueuePush(obj, 7);
    myQueuePush(obj, 8);
    myQueuePrint(obj);

    printf("Is it Empty?: %s\n", myQueueEmpty(obj) == true ? "true": "false");

    myQueueFree(obj);

    return 0;
}


