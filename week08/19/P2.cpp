#include <iostream>
using namespace std;

class MyCalendarTwo {
public:
    vector<vector<int>> single_bookings;
    vector<vector<int>> double_bookings;
    
    bool book(int start, int end) {
        for (auto i: double_bookings) {
            if (start < i[1] && end > i[0]) return false;
        }
        for (auto i: single_bookings) {
            if (start < i[1] && end > i[0]) {
                double_bookings.push_back({max(start, i[0]), min(end, i[1])});
            }
        }
        single_bookings.push_back({start, end});
        return true;
    }
};

int main() {
    MyCalendarTwo* obj = new MyCalendarTwo();
    bool param_1 = obj->book(10, 20);
    bool param_2 = obj->book(50, 60);
    bool param_3 = obj->book(10, 40);
    bool param_4 = obj->book(5, 15);
    bool param_5 = obj->book(5, 10);
    bool param_6 = obj->book(25, 55);
    cout << param_1 << endl;
    cout << param_2 << endl;
    cout << param_3 << endl;
    cout << param_4 << endl;
    cout << param_5 << endl;
    cout << param_6 << endl;

    return 0;
}