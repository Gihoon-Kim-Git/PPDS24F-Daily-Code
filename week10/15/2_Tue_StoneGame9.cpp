#include <vector>
#include <unordered_map>
#include <cstdlib> // for abs()

using namespace std;

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        unordered_map<int, int> counts;

        for (int stone : stones) {
            counts[stone % 3]++;
        }
        
        int remainder_0 = counts[0];
        int remainder_1 = counts[1];
        int remainder_2 = counts[2];

        if (remainder_0 % 2 == 0) return (remainder_1 >= 1) && (remainder_2 >= 1);
        else return abs(remainder_1 - remainder_2) > 2;
    }
};

