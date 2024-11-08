/*
There is an exam room with n seats in a single row labeled from 0 to n - 1.

When a student enters the room, they must sit in the seat that maximizes the
distance to the closest person. If there are multiple such seats, they sit in
the seat with the lowest number. If no one is in the room, then the student sits
at seat number 0.

Design a class that simulates the mentioned exam room.

Implement the ExamRoom class:

ExamRoom(int n) Initializes the object of the exam room with the number of the
seats n. int seat() Returns the label of the seat at which the next student will
set. void leave(int p) Indicates that the student sitting at seat p will leave
the room. It is guaranteed that there will be a student sitting at seat p.

Example 1:

Input
["ExamRoom", "seat", "seat", "seat", "seat", "leave", "seat"]
[[10], [], [], [], [], [4], []]
Output
[null, 0, 9, 4, 2, null, 5]

Explanation
ExamRoom examRoom = new ExamRoom(10);
examRoom.seat(); // return 0, no one is in the room, then the student sits at
seat number 0. examRoom.seat(); // return 9, the student sits at the last seat
number 9. examRoom.seat(); // return 4, the student sits at the last seat
number 4. examRoom.seat(); // return 2, the student sits at the last seat
number 2. examRoom.leave(4); examRoom.seat(); // return 5, the student sits at
the last seat number 5.

Constraints:

1 <= n <= 109
It is guaranteed that there is a student sitting at seat p.
At most 104 calls will be made to seat and leave.
*/
#include <cassert>
#include <set>

using namespace std;

class ExamRoom {
 private:
  int num_seats;
  set<int> seats;  // ordered set

 public:
  ExamRoom(int n) : num_seats(n) {}

  int seat() {
    int dist = 0;
    int curr = 0;

    if (!seats.empty()) {
      auto it = seats.begin();
      int front_dist = *it;
      if (front_dist == 0) ++it;
      dist = front_dist;

      while (it != seats.end()) {
        int mid_dist = (*it - *prev(it)) / 2;
        if (dist < mid_dist) {
          dist = mid_dist;
          curr = *prev(it) + dist;
        }
        ++it;
      }

      if (dist < ((num_seats - 1) - *prev(seats.end()))) {
        curr = num_seats - 1;
      }
    }

    return *(seats.insert(curr).first);
  }

  void leave(int p) { seats.erase(p); }
};

int main() {
  ExamRoom* room1 = new ExamRoom(10);
  assert(room1->seat() == 0);
  assert(room1->seat() == 9);
  assert(room1->seat() == 4);
  assert(room1->seat() == 2);
  room1->leave(4);
  assert(room1->seat() == 5);
}