#include <vector>
using namespace std;

class MyCalendarTwo {
public:

    vector<pair<int, int>> calendar1;
    vector<pair<int, int>> calendar2;
    
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for (auto data : calendar2) { 

            if ( (data.first <= start && start < data.second) ||  (start <= data.first && data.first < end)) {  
                return false;
            }
        }
        for (auto [s, e] : calendar1) {

            if (s <= start && start < e) {  
                calendar2.push_back({start, min(e, end)});
            }
            else if (start <= s && s < end) {
                calendar2.push_back({s, min(e, end)});
            }
        }
        calendar1.push_back({start, end});
        return true;
    }
    
};
