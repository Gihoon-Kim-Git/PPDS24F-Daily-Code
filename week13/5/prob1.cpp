#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // base case 1
        if (stones.size() == 1) {
            return stones[0];
        }
        // base case 2
        sort(stones.begin(), stones.end(), greater<int>());
        if (stones[1] == 0) {
            return stones[0];
        }
        // recursive case
        stones[0] -= stones[1];
        stones[1] = 0;
        return lastStoneWeight(stones);
    }
};
