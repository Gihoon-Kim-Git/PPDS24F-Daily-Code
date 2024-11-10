#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int start;
    int end;
} Interval;

typedef struct {
    Interval* calendar;
    Interval* overlap;
    int size[2];
    int max;
} MyCalendarTwo;


MyCalendarTwo* myCalendarTwoCreate() {
    MyCalendarTwo *obj=malloc(sizeof(MyCalendarTwo));
    obj->size[0]=0; 
    obj->size[1]=0;
    //최대 1000개만 부른다고 되어 있음 
    obj->max=1000;
    obj->calendar = malloc(sizeof(Interval)*obj->max);
    obj->overlap = malloc(sizeof(Interval)*obj->max);
    return obj;
}

bool myCalendarTwoBook(MyCalendarTwo* obj, int start, int end) {
    Interval curr;
    for (int i=0; i<obj->size[1];i++) {
        curr = obj->overlap[i];
        if (start < curr.end && end > curr.start)
            return false;
    }

    for (int i=0; i<obj->size[0];i++) {
         curr = obj->calendar[i];
         if (start < curr.end && end > curr.start) {
            //그냥 이렇게 사이즈에다가 추가하는 식으로 함...
            //나머지는 원래 파이썬과 동일
            obj->overlap[obj->size[1]].start = (start > curr.start) ? start : curr.start;
            obj->overlap[obj->size[1]].end = (end < curr.end) ? end : curr.end;
            obj->size[1]++;
         }
    }

    obj->calendar[obj->size[0]].start = start;
    obj->calendar[obj->size[0]].end = end;
    obj->size[0]++;
    return true;
}

void myCalendarTwoFree(MyCalendarTwo* obj) {
    free(obj->calendar);
    free(obj->overlap);
    free(obj);
}


int main(void){

    return 0;
}