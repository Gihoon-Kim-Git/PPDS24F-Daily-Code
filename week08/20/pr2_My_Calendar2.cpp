#include <vector>
using namespace std;

class MyCalendarTwo {
public:
        vector<vector<int>> vec1;
        vector<vector<int>> vec2;
    MyCalendarTwo() {}
    
    bool book(int start, int end) {
        for(auto vec : vec2){
            if(start < vec[1] && end > vec[0]) return false;
        }
        for(auto vec : vec1){
            if(start < vec[1] && end > vec[0]){
                vec2.push_back({max(start,vec[0]),min(end,vec[1])});}
            }
        vec1.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */