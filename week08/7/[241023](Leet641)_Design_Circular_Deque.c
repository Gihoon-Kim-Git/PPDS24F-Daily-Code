/*"""문제
Design your implementation of the circular double-ended queue (deque).

Implement the MyCircularDeque class:

MyCircularDeque(int k) Initializes the deque with a maximum size of k.
boolean insertFront() Adds an item at the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean insertLast() Adds an item at the rear of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteFront() Deletes an item from the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteLast() Deletes an item from the rear of Deque. Returns true if the operation is successful, or false otherwise.
int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.
int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.
boolean isEmpty() Returns true if the deque is empty, or false otherwise.
boolean isFull() Returns true if the deque is full, or false otherwise.
"""


"""Constraints
    1 <= k <= 1000
    0 <= value <= 1000
    At most 2000 calls will be made to insertFront, insertLast, deleteFront, deleteLast, getFront, getRear, isEmpty, isFull.
"""*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* arr;
    int cur_len;
    int max_len;
} MyCircularDeque;


MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque* new_Queue = (MyCircularDeque*)malloc(sizeof(MyCircularDeque));

    new_Queue->arr = (int*)malloc(sizeof(int) * k);
    new_Queue->cur_len = 0;
    new_Queue->max_len = k;

    return new_Queue;
}

bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if (obj->cur_len == obj->max_len) return false;
    else {
        // 한칸씩 밀어내는과정 (뒤 요소부터)
        int temp_len = obj->cur_len;
        while (temp_len > 0){
            int prev_val = obj->arr[temp_len-1];
            obj->arr[temp_len] = prev_val;
            temp_len--;
        }
        obj->arr[0] = value;
        obj->cur_len++;
        return true;
    }
}

bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if (obj->cur_len == obj->max_len) return false;
    else {
        obj->arr[obj->cur_len] = value;
        obj->cur_len++;
        return true;
    }
}

bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if (obj->cur_len == 0) return false;
    else {
        // 한 칸씩 당기기(앞에서부터)
        int temp = 0;
        while (temp < obj->cur_len - 1){
            int temp_val = obj->arr[temp + 1];
            obj->arr[temp] = temp_val;
            temp++;
        }
        obj->cur_len--;
        return true;
    }
}

bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if (obj->cur_len == 0) return false;
    else {
        obj->arr[obj->cur_len - 1] = -1;
        obj->cur_len--;
        return true;
    }
}

int myCircularDequeGetFront(MyCircularDeque* obj) {
    if (obj->cur_len == 0) return -1;
    else return obj->arr[0];
}

int myCircularDequeGetRear(MyCircularDeque* obj) {
    if (obj->cur_len == 0) return -1;
    else return obj->arr[obj->cur_len - 1];
}

bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    return (obj->cur_len == 0) ? true : false;
}

bool myCircularDequeIsFull(MyCircularDeque* obj) {
    return (obj->cur_len == obj->max_len) ? true : false;
}

void myCircularDequeFree(MyCircularDeque* obj) {
    free(obj->arr);
    free(obj);
}

/**
 * Your MyCircularDeque struct will be instantiated and called as such:
 * MyCircularDeque* obj = myCircularDequeCreate(k);
 * bool param_1 = myCircularDequeInsertFront(obj, value);
 
 * bool param_2 = myCircularDequeInsertLast(obj, value);
 
 * bool param_3 = myCircularDequeDeleteFront(obj);
 
 * bool param_4 = myCircularDequeDeleteLast(obj);
 
 * int param_5 = myCircularDequeGetFront(obj);
 
 * int param_6 = myCircularDequeGetRear(obj);
 
 * bool param_7 = myCircularDequeIsEmpty(obj);
 
 * bool param_8 = myCircularDequeIsFull(obj);
 
 * myCircularDequeFree(obj);
*/