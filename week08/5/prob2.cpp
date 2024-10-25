#include <vector>
using namespace std;

class MyCalendarTwo {
private:
    vector<pair<int, int>> singleBook;
    vector<pair<int, int>> doubleBook;

public:
    MyCalendarTwo() {
    }
    
    bool book(int start, int end) {
        // 입력된 event 가 doubleBook 과 겹치는지 검사
        for (const pair<int, int>& d : doubleBook) {    // & : 복사본이 아닌 참조(메모리 절약), const : 수정하지 않음
            // 겹친다면 : return false
            if (start < d.second && d.first < end) {
                return false;
            }
        }

        // doubleBook 과 겹치는게 없다면
        // : return true, singleBook 과 대조해서 overlap 부분은 doubleBook 에 추가, 현재 입력을 singleBook 에 추가
        for (const pair<int, int>& s : singleBook) {
            // 겹치는 부분 발견 : doubleBook 에 추가
            if (start < s.second && s.first < end) {
                int overlap_start = start > s.first? start : s.first;   // max(start, s[0])
                int overlap_end = end < s.second? end : s.second;       // min(end, s[1])
                doubleBook.push_back({overlap_start, overlap_end});
            }
        }
        singleBook.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
