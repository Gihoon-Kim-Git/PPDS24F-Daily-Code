#include <bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;

class ExamRoom {
    vector<int> room;
    int N;
public:
    ExamRoom(int n) {
        N=n;
        room.clear();
    }
    
    int seat() {
        if(room.empty()) {
            room.push_back(0);
            return 0;
        }

        int d = max(room[0]-0, N-1-room[room.size()-1]);

        for(int i=0; i<room.size()-1; i++){
            d = max(d,(room[i+1] - room[i]) /2);
        }

        if(room[0] == d){
            room.insert(room.begin(),0);
            return 0;
        }

        for(int i=0;i<room.size()-1;i++){
            if((room[i+1]-room[i]) /2 ==d) {
                room.insert(room.begin()+i+1, (room[i+1] + room[i]) /2);
                return room[i+1];
            }
        }

        room.push_back(N-1);
        return N-1;

    }

    
    void leave(int p) {
        for(int i=0; i<room.size(); i++){
            if(room[i] == p) room.erase(room.begin()+i);
        }
    }
};

/*
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */