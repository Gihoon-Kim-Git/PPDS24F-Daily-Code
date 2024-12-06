// The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

// You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

// For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

// Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.


#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        
        // 내 오른쪽에 있는 애들 중에 제일 처음 등장하는 나보다 큰 애

        map<int, int> next_greater;

        for (int i = 0; i < nums2.size(); i++) {


            next_greater[nums2[i]] = -1;

            for (int j = i + 1; j < nums2.size(); j++) {
                if (nums2[j] > nums2[i]) {
                    next_greater[nums2[i]] = nums2[j];
                    break;
                }
            }

        }

        vector<int> ans;

        for (int i = 0; i < nums1.size(); i++) {
            ans.push_back(next_greater[nums1[i]]);
        }


        return ans;
        
    }
};