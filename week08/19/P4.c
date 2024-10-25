#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct MinStack {
    int val;
    int min;
    struct MinStack *next;
} MinStack;


MinStack* minStackCreate() {
    struct MinStack *sentinel = (MinStack*)malloc(sizeof(MinStack));
    sentinel->val = INT_MIN;
    sentinel->next = NULL;
    return sentinel;
}

void minStackPush(MinStack* obj, int val) {
    MinStack *newFront = (MinStack*)malloc(sizeof(MinStack));
    newFront->val = val;
    if (obj->next != NULL && obj->next->min < val) {
        newFront->min = obj->next->min;
    } else {
        newFront->min = val;
    }
    newFront->next = obj->next;
    obj->next = newFront;
}

void minStackPop(MinStack* obj) {
    if (obj->next == NULL) return;
    MinStack *temp = obj->next;
    obj->next = temp->next;
    free(temp);
}

int minStackTop(MinStack* obj) {
    if (obj->next != NULL) {
        return obj->next->val;
    }
    return INT_MIN;
}

int minStackGetMin(MinStack* obj) {
    if (obj->next != NULL) return obj->next->min;
    return INT_MIN;
}

void minStackFree(MinStack* obj) {
    while (obj->next != NULL) {
        MinStack *temp = obj->next;
        obj->next = temp->next;
        free(temp);
    }
    free(obj);
}

int main() {
    MinStack* obj = minStackCreate();
    minStackPush(obj, -2);
    minStackPush(obj, 0);
    minStackPush(obj, -3);
    printf("%d\n", minStackGetMin(obj));
    minStackPop(obj);
    printf("%d\n", minStackTop(obj));
    printf("%d\n", minStackGetMin(obj));

    return 0;
}