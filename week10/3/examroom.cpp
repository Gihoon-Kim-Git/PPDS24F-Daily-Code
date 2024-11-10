#include <iostream>
#include <set>
using namespace std;

// The ExamRoom class simulates an exam room with `n` seats arranged in a single row, labeled from 0 to n-1.
// When a student enters the room, they choose a seat such that the distance to the closest person is maximized.
// If multiple seats have the same distance to the nearest person, the student chooses the seat with the lowest number.
// If the room is empty, the student always sits in seat 0.
// The class provides methods to simulate this behavior:
// - `ExamRoom(int n)`: Initializes the exam room with `n` seats.
// - `int seat()`: Determines and returns the seat where the next student will sit.
// - `void leave(int p)`: Marks the seat `p` as vacated by a student.
//
// Constraints:
// - 1 <= n <= 10^9 (indicating a very large potential number of seats)
// - At most 10^4 calls will be made to the `seat` and `leave` functions.

class ExamRoom {
public:
    /*
    this: special keyword that represents a pointer to the object for which a member function is called.
    used inside a member function to refer to current instance of the class that is invoking the function.
    */
    ExamRoom(int n) { // Constructor to initialize the exam room with `n` seats
        // `this`: differentiate between the member variable and the parameter
        this->n = n;
    }
    
    int seat() { // Function to seat a student in the position that maximizes distance to the closest person
        // If no one is in the room, then the student sits at seat number 0
        int student = 0;

        /*
        auto: used to let the compiler automatically deduce the type of a variable from its initializer
        */
        if (!seats.empty()) { // there is already occupied seat(s)
            // When a student enters the room, they must sit in the seat that maximizes the distance to the closest person
            int max_distance = 0;

            // 1. check distance at the beginning
            auto it = seats.begin(); // iterator pointing to the first (smallest) element in the set
            if (*it != 0) {
                int dist = *it; // distance from the start (seat 0) to the first occupied seat
                if (dist > max_distance) {
                    max_distance = dist;
                    student = 0; // sit at seat 0
                }
            }

            auto prev = seats.begin();  // Iterator for previous seat

            // 2. check distances in the middle
            // next(seats.begin()): iterator to the second element in the set
            for (auto it = next(seats.begin()); it != seats.end(); ++it) {
                // *it: seat number of the current occupied seat
                // *prev: seat number of the previous occupied seat
                int dist = (*it - *prev) / 2;  // midpoint distance between two students
                if (dist > max_distance) {
                    max_distance = dist;
                    student = *prev + dist;  // choose the middle seat
                }
                prev = it; // update prev to the current iterator so that it points to the next occupied seat in the next iteration
            }

            // 3. check distance at the end
            if (*prev != n-1) { // check if the last occupied seat is not at position n-1
                int dist = n - 1 - *prev;  // distance from the last occupied seat to the end
                if (dist > max_distance) {
                    student = n - 1;  // sit at the last seat
                }
            }
        }

        // Add the chosen seat to the set of occupied seats
        seats.insert(student);
        // Returns the label of the seat at which the next student will set
        return student;
    }
    
    void leave(int p) { // Function to indicate that the student at seat `p` leaves the room
        seats.erase(p);  // Remove seat `p` from the set of occupied seats
    }

private:
    int n;  // total number of seats
    set<int> seats;  // set to keep track of occupied seats in sorted order
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
// Example test code
int main() {
    // Instantiate the ExamRoom with 10 seats
    ExamRoom examRoom(10);

    // Simulate the operations and print the results
    cout << examRoom.seat() << endl;  // Output: 0 (No one in the room, sit at seat 0)
    cout << examRoom.seat() << endl;  // Output: 9 (Sit at the furthest seat, seat 9)
    cout << examRoom.seat() << endl;  // Output: 4 (Sit in the middle, seat 4)
    cout << examRoom.seat() << endl;  // Output: 2 (Sit in the middle, seat 2)
    examRoom.leave(4);  // Student at seat 4 leaves
    cout << examRoom.seat() << endl;  // Output: 5 (Sit at seat 5)

    return 0;
}

/*
0806a@LAPTOP-SAGEKIM MINGW64 ~/Desktop/Lecture/SNUGSDS/ProgrammingPractice/PPDS24F-Daily-Code/week10 (main)
$ g++ examroom.cpp -o exam

0806a@LAPTOP-SAGEKIM MINGW64 ~/Desktop/Lecture/SNUGSDS/ProgrammingPractice/PPDS24F-Daily-Code/week10 (main)
$ ./exam
0
9
4
2
5
*/