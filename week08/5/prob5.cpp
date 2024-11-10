#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int minimum = nums.front();
        for (int n : nums) {
            if (n < minimum) {
                minimum = n;
                break;
            }
        }
        return minimum;
    }
};
