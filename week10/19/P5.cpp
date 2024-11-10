#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int minimumOneBitOperations(int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            int bit = (int)(log2(i));
            dp[i] = (1 << (bit + 1)) - 1 - dp[i - (1 << bit)];
        }
        return dp[n];
    }
};

int main() {
    int n = 10;
    Solution solution;
    int result = solution.minimumOneBitOperations(n);
    cout << "Minimum operations to reduce " << n << " to 0: " << result << endl;
    return 0;
}