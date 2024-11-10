#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int start;
    int end;
} Interval;

typedef struct {
    Interval *single_booked;
    Interval *double_booked;
    int single_size;
    int single_capacity;
    int double_size;
    int double_capacity;
} MyCalendarTwo;

MyCalendarTwo* myCalendarTwoCreate() {
    MyCalendarTwo* mycal = (MyCalendarTwo*)malloc(sizeof(MyCalendarTwo));

    mycal->single_booked = malloc(10 * sizeof(Interval));  // 초기 크기 설정
    mycal->double_booked = malloc(10 * sizeof(Interval));  // 초기 크기 설정
    mycal->single_capacity = 10;
    mycal->double_capacity = 10;
    mycal->single_size = 0;
    mycal->double_size = 0;

    return mycal;
}

bool myCalendarTwoBook(MyCalendarTwo* obj, int start, int end) {
    for (int i = 0; i < obj->double_size;i++){
        if (obj->double_booked[i].start < end && start <obj->double_booked[i].end) return false;
    }

    Interval* temp = (Interval*)malloc(obj->single_size * sizeof(Interval));
    int temp_size = 0;
    for (int i = 0; i < obj->single_size;i++){
        if (obj->single_booked[i].start < end && start < obj->single_booked[i].end){
            Interval overlap;
            overlap.start = start > obj->single_booked[i].start ? start : obj->single_booked[i].start;
            overlap.end = end < obj->single_booked[i].end ? end : obj->single_booked[i].end;
            temp[temp_size++] = overlap;
        }
    }

    for (int i = 0; i < temp_size; i++){
        if (obj->double_size == obj->double_capacity){
            obj->double_capacity *= 2;
            obj->double_booked = realloc(obj->double_booked, obj->double_capacity * sizeof(Interval));
        }
        obj->double_booked[obj->double_size++] = temp[i];
    }
    free(temp);

    if (obj->single_size == obj->single_capacity) {
        obj->single_capacity *= 2;
        obj->single_booked = realloc(obj->single_booked, obj->single_capacity * sizeof(Interval));
    }
    obj->single_booked[obj->single_size].start = start;
    obj->single_booked[obj->single_size++].end = end;

    return true;

}

void myCalendarTwoFree(MyCalendarTwo* obj) {
    free(obj->single_booked);
    free(obj->double_booked);
}

/**
 * Your MyCalendarTwo struct will be instantiated and called as such:
 * MyCalendarTwo* obj = myCalendarTwoCreate();
 * bool param_1 = myCalendarTwoBook(obj, start, end);
 
 * myCalendarTwoFree(obj);
*/