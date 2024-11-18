#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct MyStack {
    int val;
    struct MyStack *next;
} MyStack;


MyStack* myStackCreate() {
    MyStack *sentinel = (MyStack*)malloc(sizeof(MyStack));
    sentinel->val = -999;
    sentinel->next = NULL;
    return sentinel;
}

void myStackPush(MyStack* obj, int x) {
    MyStack *new_node = (MyStack*)malloc(sizeof(MyStack));
    new_node->val = x;
    new_node->next = obj->next;
    obj->next = new_node;
}

int myStackPop(MyStack* obj) {
    if (obj->next == NULL) return -1;
    MyStack *temp = obj->next;
    int front = temp->val;
    obj->next = temp->next;
    free(temp);
    return front;
}

int myStackTop(MyStack* obj) {
    if (obj == NULL) return -1;
    return obj->next->val;
}

bool myStackEmpty(MyStack* obj) {
    return obj->next == NULL;
}

void myStackFree(MyStack* obj) {
    MyStack *cur_node = obj;
    while (cur_node != NULL) {
        MyStack *next_node = cur_node->next;
        free(cur_node);
        cur_node = next_node;
    }
}

int main() {
    MyStack* obj = myStackCreate();
    myStackPush(obj, 1);
    myStackPush(obj, 2);
    printf("%d\n", myStackTop(obj));
    printf("%d\n", myStackPop(obj));
    printf("%d\n", myStackEmpty(obj));
    myStackFree(obj);
    
    return 0;
}