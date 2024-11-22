#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* stack;
    int top;
    int capacity;
} Stack;

// 스택 생성
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->stack = (int*)malloc(capacity * sizeof(int));
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

// 스택 연산
bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int value) {
    stack->stack[++stack->top] = value;
}

int pop(Stack* stack) {
    return stack->stack[stack->top--];
}

int peek(Stack* stack) {
    return stack->stack[stack->top];
}

void freeStack(Stack* stack) {
    free(stack->stack);
    free(stack);
}


typedef struct {
    Stack* inputStack;
    Stack* outputStack;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->inputStack = createStack(100); // 적절한 초기 크기
    queue->outputStack = createStack(100);
    return queue;
}

void myQueuePush(MyQueue* obj, int x) {
    push(obj->inputStack, x);
}

int myQueuePop(MyQueue* obj) {
    if (isEmpty(obj->outputStack)){
        while (!isEmpty(obj->inputStack)){
            push(obj->outputStack, pop(obj->inputStack));
        }
    }
    return pop(obj->outputStack);
}

int myQueuePeek(MyQueue* obj) {
    if (isEmpty(obj->outputStack)){
        while (!isEmpty(obj->inputStack)){
            push(obj->outputStack, pop(obj->inputStack));
        }
    }
    return peek(obj->outputStack);
}

bool myQueueEmpty(MyQueue* obj) {
    return isEmpty(obj->inputStack) && isEmpty(obj->outputStack);
}

void myQueueFree(MyQueue* obj) {
    freeStack(obj->inputStack);
    freeStack(obj->outputStack);
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/