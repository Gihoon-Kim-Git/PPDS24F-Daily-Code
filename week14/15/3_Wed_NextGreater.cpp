#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size(), -1);
        
        unordered_map<int, int> nums1_idx;
        for (int i=0; i < nums1.size(); i++) nums1_idx[nums1[i]] = i;

        for (int i=0; i < nums2.size(); i++) {
            if (nums1_idx.find(nums2[i]) == nums1_idx.end()) continue;          // vetor에서 해당값 찾기
            for (int j=i+1; j < nums2.size(); j++) {
                if (nums2[j] > nums2[i]) {
                    int idx = nums1_idx[nums2[i]];
                    res[idx] = nums2[j];
                    break;
                }
            }
        } 
        return res;
    }
};