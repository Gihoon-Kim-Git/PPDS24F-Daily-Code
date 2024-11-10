// 855. Exam Room
#include <iostream>
#include <set>

using namespace std;

class ExamRoom {
private:
    int n;
    set<int> seats;  // To store occupied seats

public:
    ExamRoom(int n) : n(n) {}

    int seat() {
        if (seats.empty()) {
            seats.insert(0);
            return 0;
        }

        // Calculate the largest gap
        int max_dist = -1;
        int best_seat = 0;

        // Check the first seat (0 to first occupied seat)
        int first = *seats.begin();
        if (first > 0) {
            int dist = first; // distance from seat 0 to first
            if (dist > max_dist) {
                max_dist = dist;
                best_seat = 0;
            }
        }

        // Check gaps between occupied seats
        int prev = -1; // previous occupied seat
        for (int seat : seats) {
            if (prev != -1) {
                int dist = (seat - prev) / 2; // distance to the nearest seat
                if (dist > max_dist) {
                    max_dist = dist;
                    best_seat = prev + dist;
                }
            }
            prev = seat;
        }

        // Check the last seat (last occupied seat to n-1)
        if (prev != -1 && prev < n - 1) {
            int dist = n - 1 - prev; // distance from last occupied seat
            if (dist > max_dist) {
                best_seat = n - 1;
            }
        }

        seats.insert(best_seat);
        return best_seat;
    }

    void leave(int p) {
        seats.erase(p);
    }
};