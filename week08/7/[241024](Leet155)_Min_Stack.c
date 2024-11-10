/*Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
 

Constraints:

-2**31 <= val <= 2**31 - 1
Methods pop, top and getMin operations will always be called on non-empty stacks.
At most 3 * 10**4 calls will be made to push, pop, top, and getMin.*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // INT_MAX
#define MAX_INT ((1LL << 31) - 1)

typedef struct {
    int cur_size;
    int* arr;
    int max_size;
    int min_element;

} MinStack;


MinStack* minStackCreate() {
    MinStack* mystack = (MinStack*)malloc(sizeof(MinStack));
    mystack->cur_size = 0;
    mystack->max_size = 16;
    mystack->arr = (int*)malloc(sizeof(int)*mystack->max_size);
    mystack->min_element = MAX_INT;
    
    return mystack;
}

void minStackPush(MinStack* obj, int val) {
    if (obj->cur_size == obj->max_size){
        obj->max_size = 2* obj->max_size;
        obj->arr = realloc(obj->arr, sizeof(int)*obj->max_size);
    }
    obj->arr[obj->cur_size] = val;
    obj->cur_size++;

    if (val < obj->min_element) obj->min_element = val;
}

void minStackPop(MinStack* obj) {
    if (obj->arr[obj->cur_size-1] == obj->min_element){
        obj->min_element = MAX_INT;
        for (int i = 0 ; i < obj->cur_size -1 ; i++){
            if (obj->arr[i] < obj->min_element) obj->min_element = obj->arr[i];
        }
    }
    obj->cur_size--;
}

int minStackTop(MinStack* obj) {
    return obj->arr[obj->cur_size-1];
}

int minStackGetMin(MinStack* obj) {
    return obj->min_element;
}

void minStackFree(MinStack* obj) {
    free(obj->arr);
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/