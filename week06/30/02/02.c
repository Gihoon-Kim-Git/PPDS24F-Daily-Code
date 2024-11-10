#include <stdio.h>
#include <limits.h>

int solution(int A[], int N) {
    int dp[N];

    dp[0] = A[0];

    for (int i = 1; i < N; i++) {
        int max_val = INT_MIN; 
        for (int dice = 1; dice <= 6; dice++) {
            if (i - dice >= 0) {
                if (dp[i - dice] > max_val) {
                    max_val = dp[i - dice];
                }
            }
        }

        dp[i] = max_val + A[i];
    }

    return dp[N - 1];
}

int main() {
    int A[] = {1, -2, 0, 9, -1, -2};
    int N = sizeof(A) / sizeof(A[0]);
    
    int result = solution(A, N);
    printf("MAX =  %d\n", result);  
    
    return 0;
}
