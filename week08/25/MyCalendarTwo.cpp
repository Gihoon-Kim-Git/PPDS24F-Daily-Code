#include <vector>
using namespace std;

class MyCalendarTwo {
private:
    vector<pair<int, int>> singleBookings; 
    vector<pair<int, int>> doubleBookings;

public:
    MyCalendarTwo() {
    }

    bool book(int start, int end) {
        for (auto &interval : doubleBookings) {
            if (max(start, interval.first) < min(end, interval.second)) {
                return false;  
            }
        }

        for (auto &interval : singleBookings) {
            int overlapStart = max(start, interval.first);
            int overlapEnd = min(end, interval.second);
            
            if (overlapStart < overlapEnd) {
                doubleBookings.push_back({overlapStart, overlapEnd});
            }
        }


        singleBookings.push_back({start, end});
        
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */