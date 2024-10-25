#include <stdlib.h>
#include <string.h> // for memcpy

typedef struct {
    int topidx;
    int capacity; // 추가: 현재 배열의 용량
    int *arr;
} Stack;

typedef struct {
    Stack *main;
    Stack *min;
} MinStack;

void resize(Stack* stack) {
    stack->capacity *= 2; // 용량을 두 배로 늘림
    stack->arr = (int *)realloc(stack->arr, sizeof(int) * stack->capacity);
    if (!stack->arr) {
        exit(-1); // 메모리 할당 실패 시 종료
    }
}

MinStack* minStackCreate() {
    MinStack *stack = (MinStack *)malloc(sizeof(MinStack));
    stack->main = (Stack *)malloc(sizeof(Stack));
    stack->min = (Stack *)malloc(sizeof(Stack));
    
    stack->main->topidx = -1;
    stack->main->capacity = 1000;
    stack->main->arr = (int *)malloc(sizeof(int) * stack->main->capacity);
    
    stack->min->topidx = -1;
    stack->min->capacity = 1000;
    stack->min->arr = (int *)malloc(sizeof(int) * stack->min->capacity);
    
    return stack;
}

void minStackPush(MinStack* obj, int val) {
    // 스택이 꽉 찼으면 크기 두 배로 확장
    if(obj->main->topidx + 1 == obj->main->capacity) {
        resize(obj->main);
    }
    if(obj->min->topidx + 1 == obj->min->capacity) {
        resize(obj->min);
    }
    
    obj->main->arr[++obj->main->topidx] = val;
    
    if(obj->min->topidx == -1 || obj->min->arr[obj->min->topidx] >= val) {
        obj->min->arr[++obj->min->topidx] = val;
    }
}

void minStackPop(MinStack* obj) {
    if(obj->main->topidx == -1) {
        exit(-1); // 스택이 비었을 때
    }
    
    if(obj->main->arr[obj->main->topidx] == obj->min->arr[obj->min->topidx]) {
        obj->min->topidx--;
    }
    
    obj->main->topidx--;
}

int minStackTop(MinStack* obj) {
    if(obj->main->topidx == -1) {
        exit(-1); // 스택이 비었을 때
    }
    
    return obj->main->arr[obj->main->topidx];
}

int minStackGetMin(MinStack* obj) {
    if(obj->min->topidx == -1) {
        exit(-1); // 최소값 스택이 비었을 때
    }
    
    return obj->min->arr[obj->min->topidx];
}

void minStackFree(MinStack* obj) {
    free(obj->main->arr);
    free(obj->min->arr);
    free(obj->main);
    free(obj->min);
    free(obj);
}
