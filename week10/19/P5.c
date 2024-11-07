#include <stdio.h>
#include <math.h>

int minimumOneBitOperations(int n) {
    int dp[n + 1];
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int bit = (int)(log2(i));
        dp[i] = (1 << (bit + 1)) - 1 - dp[i - (1 << bit)];
    }
    return dp[n];
}

int main() {
    int n = 10;
    int result = minimumOneBitOperations(n);
    printf("Minimum operations to reduce %d to 0: %d\n", n, result);
    return 0;
}