#include <set>
#include <algorithm>
using namespace std;

class ExamRoom {
public:
    ExamRoom(int n) : n(n) {}

    int seat() {
        if (seats.empty()) {
            seats.insert(0);
            return 0;
        }

        int last_seat = -1, max_dist = 0, candidate_seat = 0;

        // Check the first seat
        auto it = seats.begin();
        int first_seat = *it;
        if (first_seat != 0) {
            max_dist = first_seat;
            candidate_seat = 0;
        }

        // Check seats in between
        for (auto it = seats.begin(); next(it) != seats.end(); ++it) {
            int seat1 = *it;
            int seat2 = *next(it);
            int dist = (seat2 - seat1) / 2;
            if (dist > max_dist) {
                max_dist = dist;
                candidate_seat = seat1 + dist;
            }
        }

        // Check the last seat
        int last_seat_occupied = *seats.rbegin();
        if (n - 1 - last_seat_occupied > max_dist) {
            candidate_seat = n - 1;
        }

        seats.insert(candidate_seat);
        return candidate_seat;
    }

    void leave(int p) {
        seats.erase(p);
    }

private:
    int n;
    set<int> seats;
};
