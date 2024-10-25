#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
//1. TieRopes
int solution(int K, int A[], int N) {
    int cnt = 0;
    int curr = 0;

    for (int i = 0; i < N; i++) {
        curr += A[i];
        if (curr >= K) {
            curr = 0;
            cnt++;
        }
    }

    return cnt;
}

//2. My Calendar 2
typedef struct {
    int* start_lst;
    int* end_lst;
    int* overlap_start_lst;
    int* overlap_end_lst;
    int count;
    int overlap_count;
} MyCalendarTwo;


MyCalendarTwo* myCalendarTwoCreate() {
    MyCalendarTwo* newCalendar = (MyCalendarTwo*)malloc(sizeof(MyCalendarTwo));
    newCalendar->start_lst = (int*)malloc(sizeof(int) * 1000);  // 이벤트 최대 1000개로 가정
    newCalendar->end_lst = (int*)malloc(sizeof(int) * 1000);
    newCalendar->overlap_start_lst = (int*)malloc(sizeof(int) * 1000);  // 이중 예약 구간
    newCalendar->overlap_end_lst = (int*)malloc(sizeof(int) * 1000);
    newCalendar->count = 0;
    newCalendar->overlap_count = 0;
    return newCalendar;

}

bool myCalendarTwoBook(MyCalendarTwo* obj, int start, int end) {
    // 1. 이중 예약된 구간과 새 이벤트가 겹치는지 확인
    for (int i = 0; i < obj->overlap_count; i++) {
        if (start < obj->overlap_end_lst[i] && end > obj->overlap_start_lst[i]) {
            // 삼중 예약이 발생하므로 false 반환
            return false;
        }
    }

    // 2. 기존 이벤트와 새 이벤트의 겹치는 구간을 확인해 이중 예약 리스트에 추가
    for (int i = 0; i < obj->count; i++) {
        if (start < obj->end_lst[i] && end > obj->start_lst[i]) {
            // 겹치는 구간이 발생 -> 이중 예약으로 저장
            int overlap_start = start > obj->start_lst[i] ? start : obj->start_lst[i];
            int overlap_end = end < obj->end_lst[i] ? end : obj->end_lst[i];
            obj->overlap_start_lst[obj->overlap_count] = overlap_start;
            obj->overlap_end_lst[obj->overlap_count] = overlap_end;
            obj->overlap_count++;
        }
    }

    // 3. 새로운 이벤트를 이벤트 리스트에 추가
    obj->start_lst[obj->count] = start;
    obj->end_lst[obj->count] = end;
    obj->count++;

    return true;
}

void myCalendarTwoFree(MyCalendarTwo* obj) {
    free(obj->start_lst);
    free(obj->end_lst);
    free(obj->overlap_start_lst);
    free(obj->overlap_end_lst);
    free(obj);
}

/**
 * Your MyCalendarTwo struct will be instantiated and called as such:
 * MyCalendarTwo* obj = myCalendarTwoCreate();
 * bool param_1 = myCalendarTwoBook(obj, start, end);

 * myCalendarTwoFree(obj);
*/


//3. Circular Deque
typedef int element;

typedef struct {
    element * data;
    int size;
    int front;
    int rear;
} MyCircularDeque;


MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque *q = (MyCircularDeque*)malloc(sizeof(MyCircularDeque));
    q->data = (element*)malloc(sizeof(element)*(k+1));
    q->front = 0;
    q->rear = 0;
    q->size = k+1;
    return q;
}

bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    if (obj->front == obj->rear) return true;
    else return false;
    
}

bool myCircularDequeIsFull(MyCircularDeque* obj) {
    if (((obj->rear+1)%obj->size) == obj->front) {
        return true;
    }
    else {
        return false;
    }
}


int myCircularDequeGetFront(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) {
        return -1;
    }
    else {
        return obj->data[(obj->front+1)%obj->size];
    }
}

int myCircularDequeGetRear(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) {
        return -1;
    }
    else {
        return obj->data[obj->rear];
    }
}


bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if (myCircularDequeIsFull(obj)) {
        return false;
    }
    obj->data[obj->front] = value;
    obj->front = (obj->front-1 + obj->size) % obj->size;
    return true;
}

bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if (myCircularDequeIsFull(obj)) {
        return false;
    }
    obj->rear = (obj->rear+1)%obj->size;
    obj->data[obj->rear] = value;
    return true;
}

bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) {
        return false;
    }
    int tmp = myCircularDequeGetFront(obj);
    obj->front = (obj->front+1)%obj->size;
    return true;
}

bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) return false;
    int tmp = myCircularDequeGetRear(obj);
    obj->rear = (obj->rear-1 + obj->size) % obj->size;
    return true;
}


void myCircularDequeFree(MyCircularDeque* obj) {
    free(obj);
}



//4. Min Stack
typedef int element;

typedef struct {
    element * array;
    int top;
    int capacity;
} MinStack;

MinStack* minStackCreate() {
    MinStack* stack = (MinStack*)malloc(sizeof(MinStack));
    stack->capacity = 100000;
    stack->top = -1;
    stack->array = (element*)malloc(sizeof(element)*stack->capacity);
    return stack;
}

void minStackPush(MinStack* obj, int val) {
    obj->array[++obj->top] = val;
}

void minStackPop(MinStack* obj) {
    obj->array[obj->top--];
}

int minStackTop(MinStack* obj) {
    return obj->array[obj->top];
}

int minStackGetMin(MinStack* obj) {
    int min_num = obj->array[0];
    for (int i = 0; i <= obj->top; i++) {
        if (obj->array[i] < min_num) min_num = obj->array[i];
    }
    return min_num;
}

void minStackFree(MinStack* obj) {
    free(obj);
}





//5. Find minimum in rotated sorted array
int findMin(int* nums, int numsSize) {
    int min_num = nums[0];
    for (int i = 0; i < numsSize; i++) {
        if (min_num > nums[i]) min_num = nums[i];
    }
    return min_num;
}