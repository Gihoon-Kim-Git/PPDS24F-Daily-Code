#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct MyQueue {
    int val;
    struct MyQueue *next;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue *sentinel = (MyQueue*)malloc(sizeof(MyQueue));
    sentinel->val = -999;
    sentinel->next = NULL;
    return sentinel;
}

void myQueuePush(MyQueue* obj, int x) {
    MyQueue *cur_node = obj;
    while (cur_node->next != NULL) {
        cur_node = cur_node->next;
    }
    MyQueue *new_node = (MyQueue*)malloc(sizeof(MyQueue));
    new_node->val = x;
    new_node->next = NULL;
    cur_node->next = new_node;
}

int myQueuePop(MyQueue* obj) {
    if (obj->next == NULL) return -1;
    MyQueue *temp = obj->next;
    int front = temp->val;
    obj->next = temp->next;
    free(temp);
    return front;
}

int myQueuePeek(MyQueue* obj) {
    if (obj == NULL) return -1;
    return obj->next->val;
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->next == NULL;
}

void myQueueFree(MyQueue* obj) {
    MyQueue *cur_node = obj;
    while (cur_node != NULL) {
        MyQueue *next_node = cur_node->next;
        free(cur_node);
        cur_node = next_node;
    }
}

int main() {
    MyQueue* obj = myQueueCreate();
    myQueuePush(obj, 1);
    myQueuePush(obj, 2);
    printf("%d\n", myQueuePeek(obj));
    printf("%d\n", myQueuePop(obj));
    printf("%d\n", myQueueEmpty(obj));
    myQueueFree(obj);
    
    return 0;
}