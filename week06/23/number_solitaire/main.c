#include <stdio.h>
#include <limits.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int solution(int A[], int N) {
    int dp[N];  // Array to store the maximum sum at each square
    
    // Initialize the dp array
    dp[0] = A[0];
    
    // Iterate through the board to fill the dp array
    for (int i = 1; i < N; i++) {
        dp[i] = INT_MIN;
        // Look at up to 6 previous squares to get the max score
        for (int j = 1; j <= 6; j++) {
            if (i - j >= 0) {
                dp[i] = max(dp[i], dp[i - j] + A[i]);
            }
        }
    }

    return dp[N - 1];  // Return the maximum result at the last square
}

int main() {
    int A[] = {1, -2, 0, 9, -1, -2};
    int N = sizeof(A) / sizeof(A[0]);
    
    printf("%d\n", solution(A, N));  // Output: 8
    return 0;
}
