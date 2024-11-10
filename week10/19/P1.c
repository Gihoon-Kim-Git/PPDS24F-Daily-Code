#include <stdio.h>
#include <limits.h>

int dp[201][201];

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int calculate(int left, int right) {
    if (left >= right) return 0;
    if (dp[left][right] != -1) return dp[left][right];

    int ans = INT_MAX;
    for (int pick=left; pick < right+1; pick++) {
        int leftCost = calculate(left, pick - 1) + pick;
        int rightCost = calculate(pick + 1, right) + pick;
        int cost = max(leftCost, rightCost);
        ans = min(ans, cost);
    }

    dp[left][right] = ans;
    return ans;
}

int getMoneyAmount(int n) {
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            dp[i][j] = -1;
        }
    }
    return calculate(1, n);
}

int main() {
    printf("%d\n", getMoneyAmount(56));
    return 0;
}