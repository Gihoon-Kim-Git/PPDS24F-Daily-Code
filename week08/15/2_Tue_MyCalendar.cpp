#include <vector>
#include <algorithm>

using namespace std;

class MyCalendarTwo {
public:
    vector<pair<int, int>> booked;
    vector<pair<int, int>> overlap;
    
    MyCalendarTwo() {        
    }
    
    bool book(int start, int end) {
        for (auto& o : overlap) {
            if (max(start, o.first) < min(end, o.second)) return false;
        }
        for (auto& b : booked) {
            if (max(start, b.first) < min(end, b.second)) 
                overlap.push_back({max(start, b.first), min(end, b.second)});
        }
        booked.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */