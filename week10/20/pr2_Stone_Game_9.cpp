#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> cnt(3,0);

        for(const int x : stones){
            cnt[x%3]++;
        }
        
        if(cnt[0]%2==0) return cnt[1] > 0 && cnt[2]>0;
        else return abs(cnt[1]-cnt[2]) >=3 ;
    }
};