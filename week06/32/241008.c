// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int solution(int A[], int N) {
    // Implement your solution here
    int *dp = (int *)malloc(N * sizeof(int));
    dp[0] = A[0];

    for (int i=1; i < N; ++i) {
        int m = dp[i-1];
        for (int j=2; j < 7; ++j) {
            if (i >= j) {
                if (dp[i-j] > m) {
                    m = dp[i-j];
                }
            }
        }
        dp[i] = m + A[i];
    }
    int result = dp[N-1];
    free(dp);
    return result;
}