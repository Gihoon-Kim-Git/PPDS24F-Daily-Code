#include <vector>

using namespace std;

class MyCalendarTwo {
public:
    vector<pair<int, int>> singleBookings;
    vector<pair<int, int>> doubleBookings;
    
    MyCalendarTwo() {}
    
    bool book(int start, int end) {

        for (auto& db : doubleBookings) {
            if (start < db.second && end > db.first){return false;}
        }
        
        for (auto& sb : singleBookings) {
            if (start < sb.second && end > sb.first) {
                int overlapStart = max(start, sb.first);
                int overlapEnd = min(end, sb.second);
                doubleBookings.push_back({overlapStart, overlapEnd});
            }
        }
        singleBookings.push_back({start, end});
        return true;
    }
};

