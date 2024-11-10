// 2029. Stone Game IX
// Medium
// Topics
// Companies
// Hint
// Alice and Bob continue their games with stones. There is a row of n stones, and each stone has an associated value. You are given an integer array stones, where stones[i] is the value of the ith stone.

// Alice and Bob take turns, with Alice starting first. On each turn, the player may remove any stone from stones. The player who removes a stone loses if the sum of the values of all removed stones is divisible by 3. Bob will win automatically if there are no remaining stones (even if it is Alice's turn).

// Assuming both players play optimally, return true if Alice wins and false if Bob wins.



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {

        vector<int> cnt(3, 0);

        for (int i = 0; i < stones.size(); i++){
            cnt[stones[i] % 3]++;
        }

        if (min(cnt[1], cnt[2]) == 0){
            return max(cnt[1], cnt[2]) >= 3 && cnt[0] % 2 == 1;
        } else{
            return abs(cnt[1] - cnt[2]) >= 3 || cnt[0] % 2 == 0;
        }
    }
};