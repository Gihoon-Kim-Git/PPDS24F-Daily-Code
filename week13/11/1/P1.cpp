#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // 이렇게 해야 min-heap이 됨
        priority_queue<int> stone;
        for(auto st: stones){
            stone.push(st);
        }
        int big;
        int mid;
        while(stone.size() >= 2){
            big = stone.top();
            stone.pop();
            mid = stone.top();
            stone.pop();
            if(big > mid){
                stone.push(big - mid);
            }
        }
        if (stone.size() == 1){
            return stone.top();
        }
        else{
            return 0;
        }
    }
};