class MyCalendarTwo {
private:
    vector<pair<int, int>> booking1;
    vector<pair<int, int>> booking2;

public:
    MyCalendarTwo() {
    }
    
    bool book(int start, int end) {
        for (auto booking : booking2) {
            if (max(booking.first, start) < min(booking.second, end)) {
                return false;
            }
        }
        for (auto booking : booking1) {
            if (max(booking.first, start) < min(booking.second, end)) {
                booking2.push_back({max(booking.first, start), min(booking.second, end)});
            }
        }
        booking1.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */