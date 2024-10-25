# include <iostream>
# include <vector>

using namespace std;

class MyCalendarTwo {
public:
    vector<pair<int, int>> schedule;
    vector<pair<int, int>> overlaps;

    MyCalendarTwo() {

    }
    
    bool book(int start, int end) {
        
        for (auto& [o_s, o_e] : overlaps){
            if (start < o_e && end > o_s){
                return false;
            }
        }

        for (auto& [s_s, s_e] : schedule){
            if (start < s_e && end > s_s){
                overlaps.push_back({max(start, s_s), min(end, s_e)});
            }
        }

        schedule.push_back({start, end});
        return true;
    }
};