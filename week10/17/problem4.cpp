// There is an exam room with n seats in a single row labeled from 0 to n - 1.

// When a student enters the room, they must sit in the seat that maximizes the distance to the closest person. If there are multiple such seats, they sit in the seat with the lowest number. If no one is in the room, then the student sits at seat number 0.

// Design a class that simulates the mentioned exam room.

// Implement the ExamRoom class:

// ExamRoom(int n) Initializes the object of the exam room with the number of the seats n.
// int seat() Returns the label of the seat at which the next student will set.
// void leave(int p) Indicates that the student sitting at seat p will leave the room. It is guaranteed that there will be a student sitting at seat p.


// 양 옆과의 거리를 계산(좌우)
// 최소 거리가 가장 큰 자리에 앉혀야 됨
// 만약 최소 거리가 같다면, 번호가 작은 자리에 앉혀야 됨

// 거리 계산 결과는 vector<pair<int, int>>로 저장
// pair<int, int, int> : {left, right}

// vector 

#include <set>
using namespace std;


class ExamRoom {
public:

    int n = 0;
    set<int> pos;

    ExamRoom(int n) {
        this->n = n;
    }
    
    int seat() {
        if (pos.empty()){
            pos.insert(0);
            return 0;
        } else{

            int max_dist = 0;
            int max_pos = 0;
            int curr = -1;

            for (int p: pos){
                if (curr == -1){
                    max_dist = p;
                    max_pos = 0;
                } else{
                    int dist = (p - curr) / 2;
                    if (dist > max_dist){
                        max_dist = dist;
                        max_pos = curr + dist;
                    }
                }
                curr = p;
            }

            if (n - 1 - curr > max_dist){
                max_pos = n - 1;
            }

            pos.insert(max_pos);
            return max_pos;
        }
        
    }
    
    void leave(int p) {
        pos.erase(p);
        
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */