/*

Leetcode 731. My callendar II

You are implementing a program to use as your calendar. We can add a new event if adding the event will not cause a triple booking.

A triple booking happens when three events have some non-empty intersection (i.e., some moment is common to all the three events.).

The event can be represented as a pair of integers start and end that represents a booking on the half-open interval [start, end), the range of real numbers x such that start <= x < end.

Implement the MyCalendarTwo class:

MyCalendarTwo() Initializes the calendar object.
boolean book(int start, int end) Returns true if the event can be added to the calendar successfully without causing a triple booking. Otherwise, return false and do not add the event to the calendar.

*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int **booked;
    int **overlapped;
    int booked_count;
    int overlapped_count;
} MyCalendarTwo;

MyCalendarTwo *myCalendarTwoCreate()
{
    MyCalendarTwo *obj = (MyCalendarTwo *)malloc(sizeof(MyCalendarTwo));

    obj->booked = (int **)malloc(sizeof(int *) * 1000);
    obj->overlapped = (int **)malloc(sizeof(int *) * 1000);
    obj->booked_count = 0;     // 초기 이벤트 수는 0
    obj->overlapped_count = 0; // 초기 중첩 이벤트 수는 0

    for (int i = 0; i < 1000; i++)
    {
        obj->booked[i] = (int *)malloc(sizeof(int) * 2);
        obj->overlapped[i] = (int *)malloc(sizeof(int) * 2);
    }

    return obj;
}

bool myCalendarTwoBook(MyCalendarTwo *obj, int start, int end)
{
    // 먼저 중첩된(overlapped) 이벤트에서 겹치는지 확인
    for (int i = 0; i < obj->overlapped_count; i++)
    {
        if (obj->overlapped[i][0] < end && obj->overlapped[i][1] > start)
        { // 삼중 예약(triplet)이면 false 반환
            return false;
        }
    }

    // 중첩되지 않으면 기존 예약(booked)에서 겹치는지 확인하고 중복된 구간을 overlapped에 추가
    for (int i = 0; i < obj->booked_count; i++)
    {
        if (obj->booked[i][0] < end && obj->booked[i][1] > start)
        {
            int max_start = obj->booked[i][0] > start ? obj->booked[i][0] : start;
            int min_end = obj->booked[i][1] < end ? obj->booked[i][1] : end;
            obj->overlapped[obj->overlapped_count][0] = max_start;
            obj->overlapped[obj->overlapped_count][1] = min_end;
            obj->overlapped_count++; // 중첩된 이벤트 수 증가
        }
    }

    // 새로운 예약을 booked에 추가
    obj->booked[obj->booked_count][0] = start;
    obj->booked[obj->booked_count][1] = end;
    obj->booked_count++; // 예약된 이벤트 수 증가
    return true;
}

void myCalendarTwoFree(MyCalendarTwo *obj)
{
    for (int i = 0; i < 1000; i++)
    {
        free(obj->booked[i]);
        free(obj->overlapped[i]);
    }
    free(obj->booked);
    free(obj->overlapped);
    free(obj);
}
