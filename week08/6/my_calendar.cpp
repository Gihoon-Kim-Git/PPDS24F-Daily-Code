/*
You are implementing a program to use as your calendar. We can add a new event
if adding the event will not cause a triple booking.

A triple booking happens when three events have some non-empty intersection
(i.e., some moment is common to all the three events.).

The event can be represented as a pair of integers start and end that represents
a booking on the half-open interval [start, end), the range of real numbers x
such that start <= x < end.

Implement the MyCalendarTwo class:

MyCalendarTwo() Initializes the calendar object.
boolean book(int start, int end) Returns true if the event can be added to the
calendar successfully without causing a triple booking. Otherwise, return false
and do not add the event to the calendar.

Example 1:

Input
["MyCalendarTwo", "book", "book", "book", "book", "book", "book"]
[[], [10, 20], [50, 60], [10, 40], [5, 15], [5, 10], [25, 55]]
Output
[null, true, true, true, false, true, true]

Explanation
MyCalendarTwo myCalendarTwo = new MyCalendarTwo();
myCalendarTwo.book(10, 20); // return True, The event can be booked.
myCalendarTwo.book(50, 60); // return True, The event can be booked.
myCalendarTwo.book(10, 40); // return True, The event can be double booked.
myCalendarTwo.book(5, 15);  // return False, The event cannot be booked, because
it would result in a triple booking.
myCalendarTwo.book(5, 10); // return True,
The event can be booked, as it does not use time 10 which is already double
booked.
myCalendarTwo.book(25, 55); // return True, The event can be booked, as
the time in [25, 40) will be double booked with the third event, the time [40,
50) will be single booked, and the time [50, 55) will be double booked with the
second event.


Constraints:

0 <= start < end <= 109
At most 1000 calls will be made to book.
*/
#include <cassert>
#include <cstdbool>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class MyCalendarTwo {
 public:
  const static int kMaxBooking = 2;
  map<int, int> cal;

  MyCalendarTwo() : cal() {}

  bool LineSweep() {
    int prefix_sum = 0;
    for (const auto& kv : cal) {
      prefix_sum += kv.second;
      if (prefix_sum > kMaxBooking) {
        return false;
      }
    }
    return true;
  }
  /**
   * @brief Return true if given event [start, end)
   * does not cause a triple booking.
   *
   * @param start Inclusive
   * @param end Exclusive
   * @return true if the event can be added
   * @return false
   */
  bool book(int start, int end) {
    ++cal[start];
    --cal[end];

    if (LineSweep()) return true;

    // Revert
    --cal[start];
    ++cal[end];

    if (cal[start] == 0) cal.erase(start);
    if (cal[end] == 0) cal.erase(end);

    return false;
  }
};

int main() {
  MyCalendarTwo* mc = new MyCalendarTwo();
  assert(mc->book(10, 20) == true);
  assert(mc->book(50, 60) == true);
  assert(mc->book(10, 40) == true);
  assert(mc->book(5, 15) == false);
  assert(mc->book(5, 10) == true);
  assert(mc->book(25, 55) == true);
  free(mc);

  MyCalendarTwo* mc2 = new MyCalendarTwo();
  assert(mc->book(26, 35) == true);
  assert(mc->book(26, 32) == true);
  assert(mc->book(25, 32) == false);
  assert(mc->book(18, 26) == true);
  assert(mc->book(40, 45) == true);
  assert(mc->book(19, 26) == true);
  assert(mc->book(48, 50) == true);
  assert(mc->book(1, 6) == true);
  assert(mc->book(46, 50) == true);
  assert(mc->book(11, 18) == true);
  free(mc2);

  MyCalendarTwo* mc3 = new MyCalendarTwo();
  assert(mc->book(24, 40) == true);
  assert(mc->book(43, 50) == true);
  assert(mc->book(27, 43) == true);
  assert(mc->book(5, 21) == true);
  assert(mc->book(30, 40) == false);
  assert(mc->book(14, 29) == false);
  assert(mc->book(3, 19) == true);
  assert(mc->book(3, 14) == false);
  assert(mc->book(25, 39) == false);
  assert(mc->book(6, 19) == false);
  free(mc3);
}
