#include <iostream>
using namespace std;

class Solution {
public:
    int findMinHelp(vector<int> nums, int start, int end) {
        if (end - start == 0) return nums[start];
        int mid = (start + end) / 2;
        int left = findMinHelp(nums, start, mid);
        int right = findMinHelp(nums, mid+1, end);
        return min(left, right);
    }

    int findMin(vector<int> nums) {
        return findMinHelp(nums, 0, nums.size()-1);
    }
};

int main() {
    // vector<int> nums = {1,3,5};
    vector<int> nums = {2,2,2,0,1};
    Solution result;
    cout << result.findMin(nums) << endl;

    return 0;
}