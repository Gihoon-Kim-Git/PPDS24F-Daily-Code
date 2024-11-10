#include <bits/stdc++.h>
using namespace std;

class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    map<int,int> cnt;
    bool book(int start, int end) {
        cnt[start]++;
        cnt[end]--;
        int ing = 0;

        for(auto &[time, change] : cnt){
            ing += change;
            if(ing >=3){
                cnt[start]--;
                cnt[end]++;
                return false;
            }
        }
        return true;

    }
};