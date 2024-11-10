#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> count(3, 0);
        
        // Count stones based on modulo 3 values
        for (int stone : stones) {
            count[stone % 3]++;
        }
        
        // Check the winning conditions based on the count of stones
        if (count[0] % 2 == 0) {
            // If count[0] is even, Alice wins if both count[1] and count[2] are non-zero
            return count[1] >= 1 && count[2] >= 1;
        } else {
            // If count[0] is odd, Alice wins if the absolute difference between count[1] and count[2] is greater than 2
            return abs(count[1] - count[2]) > 2;
        }
    }
};
