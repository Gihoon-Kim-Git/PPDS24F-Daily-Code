#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct MyCircularDeque {
    int val;
    int size;
    int capa;
    struct MyCircularDeque *next;
} MyCircularDeque;


MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque *sentinel = (MyCircularDeque*)malloc(sizeof(MyCircularDeque));
    sentinel->val = -1;
    sentinel->size = 0;
    sentinel->capa = k;
    sentinel->next = NULL;
    return sentinel;
}

bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if (obj->size >= obj->capa) return false;
    MyCircularDeque *newFront = (MyCircularDeque*)malloc(sizeof(MyCircularDeque));
    newFront->val = value;
    newFront->next = obj->next;
    obj->next = newFront;
    obj->size++;
    return true;
}

bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if (obj->size >= obj->capa) return false;
    MyCircularDeque *curNode = obj;
    while (curNode->next != NULL) {
        curNode = curNode->next;
    }
    MyCircularDeque *newLast = (MyCircularDeque*)malloc(sizeof(MyCircularDeque));
    newLast->val = value;
    newLast->next = NULL;
    curNode->next = newLast;
    obj->size++;
    return true;
}

bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if (obj->next == NULL) return false;
    MyCircularDeque *temp = obj->next;
    obj->next = temp->next;
    free(temp);
    obj->size--;
    return true;
}

bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if (obj->next == NULL) return false;
    MyCircularDeque *curNode = obj;
    MyCircularDeque *prevNode = NULL;
    while (curNode->next != NULL) {
        prevNode = curNode;
        curNode = curNode->next;
    }
    if (prevNode != NULL) prevNode->next = NULL;
    free(curNode);
    obj->size--;
    return true;
}

int myCircularDequeGetFront(MyCircularDeque* obj) {
    if (obj->next != NULL) {
        MyCircularDeque *obj_next = obj->next;
        return obj_next->val;
    }
    return -1;
}

int myCircularDequeGetRear(MyCircularDeque* obj) {
    MyCircularDeque *curNode = obj;
    while (curNode->next != NULL) curNode = curNode->next;
    return curNode->val;
}

bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    return obj->size == 0;
}

bool myCircularDequeIsFull(MyCircularDeque* obj) {
    return obj->size == obj->capa;
}

void myCircularDequeFree(MyCircularDeque* obj) {
    while (obj->next != NULL) {
        MyCircularDeque *temp = obj->next;
        obj->next = temp->next;
        free(temp);
    }
    free(obj);
}

int main() {
    MyCircularDeque* obj = myCircularDequeCreate(3);
    bool param_1 = myCircularDequeInsertLast(obj, 1);
    bool param_2 = myCircularDequeInsertLast(obj, 2);
    bool param_3 = myCircularDequeInsertFront(obj, 3);
    bool param_4 = myCircularDequeInsertFront(obj, 4);
    int param_5 = myCircularDequeGetRear(obj);
    bool param_6 = myCircularDequeIsFull(obj);
    bool param_7 = myCircularDequeDeleteLast(obj);
    bool param_8 = myCircularDequeInsertFront(obj, 4);
    int param_9 = myCircularDequeGetFront(obj);
    printf("%d\n", param_1);
    printf("%d\n", param_2);
    printf("%d\n", param_3);
    printf("%d\n", param_4);
    printf("%d\n", param_5);
    printf("%d\n", param_6);
    printf("%d\n", param_7);
    printf("%d\n", param_8);
    printf("%d\n", param_9);

    return 0;
}