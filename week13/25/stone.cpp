#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while (stones.size() > 1) {
            sort(stones.begin(), stones.end());
            int first = stones.back(); 
            stones.pop_back(); 
            int second = stones.back(); 
            stones.pop_back();

            if (first != second) {
                stones.push_back(first - second); 
            }
        }

        return stones.empty() ? 0 : stones[0];
    }
};

int main() {
    Solution sol;
    vector<int> test = {2, 7, 4, 1, 8, 1};
    cout << sol.lastStoneWeight(test) << endl; // 출력: 1
    return 0;
}