#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int minCostClimbingStairs(const std::vector<int>& cost) {
        if (cost.empty()) return 0;
        int n = cost.size();
        std::vector<int> dp(n);
        dp[0] = cost[0];
        if (n >= 2) {
            dp[1] = cost[1];
        }
        
        for (int i = 2; i < n; ++i) {
            dp[i] = cost[i] + std::min(dp[i-1], dp[i-2]);
        }
        
        return std::min(dp[n-1], dp[n-2]);
    }
};

// Driver Code
int main() {
    std::vector<int> cost = {10, 15, 20};
    Solution sol;
    int result = sol.minCostClimbingStairs(cost);
    std::cout << "Minimum cost to climb stairs: " << result << std::endl;
    
    return 0;
}
