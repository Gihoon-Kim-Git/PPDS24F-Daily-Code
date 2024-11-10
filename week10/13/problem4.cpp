#include <set>
#include <iostream>
using namespace std;

class ExamRoom {
public:
    int n;  // 좌석의 개수
    set<int> seats;  // 이미 점유된 좌석 번호를 저장하는 집합

    ExamRoom(int n) {
        this->n = n;
    }
    
    int seat() {
        if (seats.empty()) {
            // 비어있으면 첫 번째 학생이 0번 자리에 앉는다.
            seats.insert(0);
            return 0;
        }

        int maxDist = 0;
        int seatToSit = 0;
        
        // 첫 번째 자리를 고려
        auto it = seats.begin();
        if (*it != 0) {
            maxDist = *it;
            seatToSit = 0;
        }

        // 중간에 앉는 경우를 고려
        int prev = -1;
        for (int s : seats) {
            if (prev != -1) {
                int dist = (s - prev) / 2;
                if (dist > maxDist) {
                    maxDist = dist;
                    seatToSit = prev + dist;
                }
            }
            prev = s;
        }

        // 마지막 자리를 고려
        if (n - 1 - *seats.rbegin() > maxDist) { //reverse begin이라서 역순서를 조회하는 것
            seatToSit = n - 1;
        }

        seats.insert(seatToSit);
        return seatToSit;
    }
    
    void leave(int p) {
        // p 자리를 비운다.
        seats.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */

