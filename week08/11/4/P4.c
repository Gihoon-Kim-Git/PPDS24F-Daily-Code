#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int min[30000];
    int st[30000];
    int size;
} MinStack;


MinStack* minStackCreate() {
    MinStack* z = (MinStack*)malloc(sizeof(MinStack));
    z->size = 0;
    return z;
}

void minStackPush(MinStack* obj, int val) {
    obj->st[obj->size] = val;
    if(obj->size == 0){
        obj->min[0] = val;
    }
    else{
        if (val < obj->min[obj->size-1]){
            obj->min[obj->size] = val;
        }
        else{
            obj->min[obj->size] = obj->min[obj->size-1];
        }
    }
    obj->size++;
}

void minStackPop(MinStack* obj) {
    obj->st[obj->size-1] = 0;
    obj->min[obj->size-1] = 0;
    obj->size--;
}

int minStackTop(MinStack* obj) {
    return obj->st[obj->size-1];
}

int minStackGetMin(MinStack* obj) {
    return obj->min[obj->size-1];
}

void minStackFree(MinStack* obj) {
    free(obj);
}


int main(void) {
    MinStack* stack = minStackCreate();

    printf("Pushing values 3, 5, 2, 1, 4 onto the stack.\n");
    minStackPush(stack, 3);
    minStackPush(stack, 5);
    minStackPush(stack, 2);
    minStackPush(stack, 1);
    minStackPush(stack, 4);

    printf("Top value: %d\n", minStackTop(stack));       // Expected: 4
    printf("Minimum value: %d\n", minStackGetMin(stack)); // Expected: 1

    printf("\nPopping top value.\n");
    minStackPop(stack);

    printf("Top value: %d\n", minStackTop(stack));       // Expected: 1
    printf("Minimum value: %d\n", minStackGetMin(stack)); // Expected: 1

    printf("\nPopping top value.\n");
    minStackPop(stack);

    printf("Top value: %d\n", minStackTop(stack));       // Expected: 2
    printf("Minimum value: %d\n", minStackGetMin(stack)); // Expected: 2

    printf("\nPushing value 0 onto the stack.\n");
    minStackPush(stack, 0);

    printf("Top value: %d\n", minStackTop(stack));       // Expected: 0
    printf("Minimum value: %d\n", minStackGetMin(stack)); // Expected: 0

    minStackFree(stack);
    return 0;
}