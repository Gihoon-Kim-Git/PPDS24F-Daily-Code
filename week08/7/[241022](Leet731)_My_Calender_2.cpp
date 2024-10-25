/*문제
You are implementing a program to use as your calendar. We can add a new event if adding the event will not cause a triple booking.

A triple booking happens when three events have some non-empty intersection (i.e., some moment is common to all the three events.).

The event can be represented as a pair of integers start and end that represents a booking on the half-open interval [start, end), the range of real numbers x such that start <= x < end.

Implement the MyCalendarTwo class:
    MyCalendarTwo() Initializes the calendar object.
    boolean book(int start, int end) Returns true if the event can be added to the calendar successfully without causing a triple booking. Otherwise, return false and do not add the event to the calendar.
*/
/*Constraints
    0 <= start < end <= 109
    At most 1000 calls will be made to book.
*/


#include <iostream>
#include <vector>
using namespace std;

class MyCalendarTwo {
    vector<vector<int>> DB_list;
    vector<vector<int>> SB_list; 
public:
    MyCalendarTwo() {
        DB_list = {};
        SB_list = {};
    }
    
    bool book(int start, int end) {
        for (auto t : DB_list){
            if (t[0] < end && start < t[1]) return false;
        }

        vector<vector<int>> temp;
        for (auto t : SB_list){
            if (t[0] < end && start < t[1]){
                int overlap_start = max(t[0], start);
                int overlap_end = min(t[1], end);
                temp.push_back({overlap_start, overlap_end});
            }
        }

        for (auto t : temp){
            DB_list.push_back(t);
        }

        SB_list.push_back({start, end});
        
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */