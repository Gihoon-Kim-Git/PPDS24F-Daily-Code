#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int start;
    int end;
} Interval;

typedef struct {
    Interval *bookings;
    Interval *overlaps;
    int bookingsSize;
    int overlapsSize;
    int capacity;
} MyCalendarTwo;

// MyCalendarTwo 초기화 
MyCalendarTwo* myCalendarTwoCreate() {
    MyCalendarTwo* obj = (MyCalendarTwo*)malloc(sizeof(MyCalendarTwo));
    obj->capacity = 1000;  // 임의의 용량 설정
    obj->bookings = (Interval*)malloc(sizeof(Interval) * obj->capacity);
    obj->overlaps = (Interval*)malloc(sizeof(Interval) * obj->capacity);
    obj->bookingsSize = 0;
    obj->overlapsSize = 0;
    return obj;
}

// 두 구간의 겹치는 구간 계산
Interval getOverlap(int start1, int end1, int start2, int end2) {
    Interval overlap;
    overlap.start = (start1 > start2) ? start1 : start2;
    overlap.end = (end1 < end2) ? end1 : end2;
    return overlap;
}

//두 구간이 겹치는지 확인
bool isOverlap(int start1, int end1, int start2, int end2) {
    return start1 < end2 && start2 < end1;
}

bool myCalendarTwoBook(MyCalendarTwo* obj, int start, int end) {
    // 1. 먼저 겹치는 구간에 대해 확인
    for (int i = 0; i < obj->overlapsSize; i++) {
        if (isOverlap(start, end, obj->overlaps[i].start, obj->overlaps[i].end)) {
            return false;  // 삼중 예약 
        }
    }
    
    // 2. 기존 예약과의 겹치는 구간을 확인하고, 겹치면 overlaps에 추가
    for (int i = 0; i < obj->bookingsSize; i++) {
        if (isOverlap(start, end, obj->bookings[i].start, obj->bookings[i].end)) {
            Interval overlap = getOverlap(start, end, obj->bookings[i].start, obj->bookings[i].end);
            obj->overlaps[obj->overlapsSize++] = overlap;
        }
    }

    // 3. 새로운 예약을 추가
    obj->bookings[obj->bookingsSize].start = start;
    obj->bookings[obj->bookingsSize].end = end;
    obj->bookingsSize++;

    return true;  
}

void myCalendarTwoFree(MyCalendarTwo* obj) {
    free(obj->bookings);
    free(obj->overlaps);
    free(obj);
}


int main() {
    MyCalendarTwo* myCalendar = myCalendarTwoCreate();

    printf("%d\n", myCalendarTwoBook(myCalendar, 10, 20)); 
    printf("%d\n", myCalendarTwoBook(myCalendar, 50, 60)); 
    printf("%d\n", myCalendarTwoBook(myCalendar, 10, 40)); 
    printf("%d\n", myCalendarTwoBook(myCalendar, 5, 15));  
    printf("%d\n", myCalendarTwoBook(myCalendar, 5, 10));  
    printf("%d\n", myCalendarTwoBook(myCalendar, 25, 55)); 

    myCalendarTwoFree(myCalendar);
    return 0;
}