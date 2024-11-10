#include <iostream>
#include <vector>
using namespace std;

// Problem Summary:
// You are implementing a calendar program where you can add events to the calendar.
// An event is defined by a start time and an end time in a half-open interval [start, end).
// The goal is to ensure that adding a new event does not cause a triple booking, 
// which occurs when three events overlap at the same time.
// Implement the MyCalendarTwo class, which supports booking events without causing 
// triple bookings, and returns true if the event can be booked successfully, or false otherwise.

class MyCalendarTwo {
public:
    // Constructor: initializes the calendar object
    MyCalendarTwo() {
        // No initialization required for the vectors
    }
    
    // Method to book an event
    bool book(int startTime, int endTime) {

        /*
        Explanation of auto& in OOP:

        auto: used to automatically deduce the type of a variable based on the initializer or the context in which it is used
        (makes the code more readable and easier to maintain, especially when dealing with complex types)

        &: denotes a reference (an alias for another variable,
        meaning that any modification done to the reference will directly affect the original variable)
        */

        // [event.first, event.second): existing event's interval
        // [startTime, endTime): new event's interval
        // max(event.first, startTime): finds later of two start times, gives earliest time when both intervals could possibly overlap
        // min(event.second, endTime): finds earlier of two end times, gives latest time when both intervals could possibly overlap
        // checks if the computed overlap interval has a positive length

        // iteration over all double bookings to check if new event will cause a triple booking
        for (auto& event : doubleBooked) {
            // if there is any overlap with an existing double booking, a triple booking would occur
            if (max(event.first, startTime) < min(event.second, endTime)) {
                return false;
            }
        }

        // iteration over all existing single bookings
        for (auto& event : singleBooked) {
            // if overlap exists, this new booking will be a double booking
            if (max(event.first, startTime) < min(event.second, endTime)) {
                doubleBooked.push_back({max(event.first, startTime), min(event.second, endTime)});
            }
        }

        singleBooked.push_back({startTime, endTime});
        return true;
    }

private:
    vector<pair<int, int>> singleBooked;
    vector<pair<int, int>> doubleBooked;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start, end);
 */

// Example usage
int main() {
    MyCalendarTwo myCalendarTwo;
    cout << myCalendarTwo.book(10, 20) << endl; // Output: 1 (true), event can be booked.
    cout << myCalendarTwo.book(50, 60) << endl; // Output: 1 (true), event can be booked.
    cout << myCalendarTwo.book(10, 40) << endl; // Output: 1 (true), double booking allowed.
    cout << myCalendarTwo.book(5, 15) << endl;  // Output: 0 (false), would cause a triple booking.
    cout << myCalendarTwo.book(5, 10) << endl;  // Output: 1 (true), event can be booked.
    cout << myCalendarTwo.book(25, 55) << endl; // Output: 1 (true), event can be booked.
    return 0;
}

/*
0806a@LAPTOP-SAGEKIM MINGW64 ~/Desktop/Lecture/SNUGSDS/ProgrammingPractice/PPDS24F-Daily-Code/week08 (main)
$ g++ mycalendar2.cpp -o cal

0806a@LAPTOP-SAGEKIM MINGW64 ~/Desktop/Lecture/SNUGSDS/ProgrammingPractice/PPDS24F-Daily-Code/week08 (main)
$ ./cal
1
1
1
0
1
1
*/