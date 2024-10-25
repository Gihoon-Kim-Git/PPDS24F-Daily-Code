#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {

        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return nums[0] <= nums[1]? nums[0] : nums[1];

        int lowIdx = 0;
        int highIdx = nums.size()-1;
        
        while(lowIdx < highIdx) {
            int midIdx = (lowIdx + highIdx)/2;
            if ( nums[midIdx] < nums[lowIdx]) {
                highIdx = midIdx;
            } else if (nums[midIdx] > nums[highIdx]) { 
                lowIdx = midIdx+1; 
            } else { highIdx--;
            }
        }
        return nums[lowIdx]; 
    }
    
};
