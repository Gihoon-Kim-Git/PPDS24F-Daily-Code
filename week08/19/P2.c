#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int start, end;
} Interval;

typedef struct {
    Interval* cal;
    Interval* intrscs;
    int cal_size;
    int intrscs_size;
} MyCalendarTwo;

MyCalendarTwo* myCalendarTwoCreate() {
    MyCalendarTwo* obj = (MyCalendarTwo*)malloc(sizeof(MyCalendarTwo));
    obj->cal = (Interval*)malloc(1000 * sizeof(Interval));  // Initial size of 1000
    obj->intrscs = (Interval*)malloc(1000 * sizeof(Interval));
    obj->cal_size = 0;
    obj->intrscs_size = 0;
    return obj;
}

bool myCalendarTwoBook(MyCalendarTwo* obj, int start, int end) {
    for (int i = 0; i < obj->intrscs_size; i++) {
        Interval x = obj->intrscs[i];
        if ((start < x.start && end > x.start) || (start >= x.start && start < x.end)) {
            return false;
        }
    }

    for (int i = 0; i < obj->cal_size; i++) {
        Interval x = obj->cal[i];
        if ((start < x.start && end > x.start) || (start >= x.start && start < x.end)) {
            int cs = (x.start > start) ? x.start : start;
            int ce = (x.end < end) ? x.end : end;
            obj->intrscs[obj->intrscs_size++] = (Interval){cs, ce};
        }
    }

    obj->cal[obj->cal_size++] = (Interval){start, end};
    return true;
}

void myCalendarTwoFree(MyCalendarTwo* obj) {
    free(obj->cal);
    free(obj->intrscs);
    free(obj);
}

int main() {
    MyCalendarTwo* obj = myCalendarTwoCreate();
    bool param_1 = myCalendarTwoBook(obj, 10, 20);
    bool param_2 = myCalendarTwoBook(obj, 50, 60);
    bool param_3 = myCalendarTwoBook(obj, 10, 40);
    bool param_4 = myCalendarTwoBook(obj, 5, 15);
    bool param_5 = myCalendarTwoBook(obj, 5, 10);
    bool param_6 = myCalendarTwoBook(obj, 25, 55);
    printf("%d\n", param_1);
    printf("%d\n", param_2);
    printf("%d\n", param_3);
    printf("%d\n", param_4);
    printf("%d\n", param_5);
    printf("%d\n", param_6);
    
    return 0;
}