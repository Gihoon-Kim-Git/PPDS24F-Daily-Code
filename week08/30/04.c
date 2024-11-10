#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef struct {
    int *stack;
    int *minStack;
    int top;
    int minTop;
    int capacity;
} MinStack;

MinStack* minStackCreate() {
    MinStack *obj = (MinStack*)malloc(sizeof(MinStack));
    obj->capacity = MAX;
    obj->stack = (int*)malloc(sizeof(int) * obj->capacity);
    obj->minStack = (int*)malloc(sizeof(int) * obj->capacity);
    obj->top = -1;
    obj->minTop = -1;
    return obj;
}

void minStackPush(MinStack* obj, int val) {
    obj->top++;
    obj->stack[obj->top] = val;
    
    // 최소값 스택에 푸시
    if (obj->minTop == -1 || val <= obj->minStack[obj->minTop]) {
        obj->minTop++;
        obj->minStack[obj->minTop] = val;
    }
}

void minStackPop(MinStack* obj) {
    // 스택에서 값 제거
    if (obj->stack[obj->top] == obj->minStack[obj->minTop]) {
        obj->minTop--;  // 최소값 스택에서 제거
    }
    obj->top--;  // 일반 스택에서 제거
}

int minStackTop(MinStack* obj) {
    return obj->stack[obj->top];
}

int minStackGetMin(MinStack* obj) {
    return obj->minStack[obj->minTop];
}

void minStackFree(MinStack* obj) {
    free(obj->stack);
    free(obj->minStack);
    free(obj);
}


int main() {
    MinStack* minStack = minStackCreate();

    minStackPush(minStack, -2);       
    minStackPush(minStack, 0);        
    minStackPush(minStack, -3);       // [-2, 0, -3]
    
    printf("Min: %d\n", minStackGetMin(minStack)); 

    minStackPop(minStack);            // [-2, 0]
    printf("Top: %d\n", minStackTop(minStack));    
    printf("Min: %d\n", minStackGetMin(minStack)); 

    minStackFree(minStack);           

    return 0;
}