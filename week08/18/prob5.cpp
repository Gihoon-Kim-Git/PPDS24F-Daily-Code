#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int min_num = INT_MAX;
        for (int i = 0; i<nums.size();i++){
            min_num = min(min_num, nums[i]);
        }
        
        return min_num;
    }
};