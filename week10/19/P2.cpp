#include <iostream>
using namespace std;

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> stoneDict(3, 0);
        for (auto s: stones) {
            int num = s % 3;
            stoneDict[num]++;
        }
        if (stoneDict[0] % 2 == 0) {
            if (stoneDict[1] > 0 && stoneDict[2] > 0) return true;
            else return false;
        } else {
            if ((stoneDict[1]-stoneDict[2] > 2) || (stoneDict[1]-stoneDict[2] < -2)) return true;
            return false;
        }
    }
};

int main() {
    vector<int> stones = {2,2,2,0};
    Solution result;
    cout << result.stoneGameIX(stones) << endl;

    return 0;
}