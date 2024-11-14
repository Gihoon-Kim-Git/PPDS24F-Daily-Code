#include <vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> memo(cost.size(), -1);
        return min(helper(cost, memo, 0), helper(cost, memo, 1));
    }

    int min(int a, int b) {
        if (a < b) return a;
        else return b;
    }

    int helper(const vector<int>& cost, vector<int>& memo, int i) {
        // i-th step 에서 시작해서 top floor 까지 가는데 필요한 최소 비용 (i-th step 의 비용도 계산에 포함)

        // base case
        // - 현재 위치 : 마지막 step
        if (i == cost.size()-1) {
            if (memo[i] < 0) memo[i] = cost[i];
            return memo[i];
        }
        // - 현재 위치 : 뒤에서 2번째 step
        else if (i == cost.size()-2) {
            if (memo[i] < 0) memo[i] = cost[i];
            return memo[i];
        }

        // recursive case
        else {
            if (memo[i] < 0) {
                int one_step = cost[i] + helper(cost, memo, i+1);
                int two_step = cost[i] + helper(cost, memo, i+2);
                memo[i] = min(one_step, two_step);
            }
            return memo[i];
        }
    }
};
