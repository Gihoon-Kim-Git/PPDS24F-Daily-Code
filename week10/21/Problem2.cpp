#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        if(stones.size() == 1) return false;
        int stone[3] = {};
        for(int i=0; i <stones.size(); i++){
            int n = stones[i]%3;
            if(n==0) stone[0]++;
            else if(n==1) stone[1]++;
            else if(n==2) stone[2]++;            
        }

        if(stone[0]%2 == 0) return stone[1]>0 && stone[2]>0;
        else return abs(stone[1]-stone[2])>2;
    }
};