#include <stdio.h>

int main() {
    int T, N;
    scanf("%d", &T);  // Read number of test cases

    while (T--) {
        scanf("%d", &N);  // Read N
        int dp[N + 1];

        // Initialize dp array
        for (int i = 1; i <= N; i++) {
            if (i == 1) {
                dp[i] = 1;
            } else if (i == 2) {
                dp[i] = 2;
            } else if (i == 3) {
                dp[i] = 4;
            } else {
                dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
            }
        }

        printf("%d\n", dp[N]);  // Output result for N
    }

    return 0;
}

