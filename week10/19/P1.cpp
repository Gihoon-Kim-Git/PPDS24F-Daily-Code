#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<int, int> memo;

    int dp(int left, int right) {
        int key = left * 1000 + right; // left, right를 하나의 고유 키로 만들기 위해
        if (memo.find(key) != memo.end()) return memo[key];
        if (left >= right) return 0;
        int ans = INT_MAX;
        for (int pick=left; pick<right+1; pick++) {
            int leftCost = dp(left, pick - 1) + pick;
            int rightCost = dp(pick + 1, right) + pick;
            int cost = max(leftCost, rightCost);
            ans = min(ans, cost);
        }
        memo[key] = ans;
        return ans;
    }

    int getMoneyAmount(int n) {
        return dp(1, n);
    }
};

int main() {
    Solution result;
    cout << result.getMoneyAmount(56) << endl;

    return 0;
}