#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    int findPosition(int num, vector<int>& nums) {
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == num) {
                return i;
            }
        }
        return -1;
    }

    int helper(int idx, vector<int>& nums) {
        for (int i=idx; i<nums.size(); i++) {
            if (nums[i] > nums[idx]) {
                return nums[i];
            }
        }
        return -1;
    }

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> answer;
        for (int i=0; i<nums1.size(); i++) {
            int idx = findPosition(nums1[i], nums2);
            if (idx < 0) cout << "Error!" << endl;
            int ans_i = helper(idx, nums2);
            answer.push_back(ans_i);
        }

        return answer;
    }
};
