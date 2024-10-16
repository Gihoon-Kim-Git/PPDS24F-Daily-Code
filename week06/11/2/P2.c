#include <stdio.h>
#include <stdlib.h>


int solution(int A[], int N){
    int dp[1000000] = {0};
    if(N == 1){
        return A[0];
    }
    else if(N == 2){
        return A[0] + A[1];
    }
    dp[0] = A[0];
    dp[1] = A[0] + A[1];

    for(int i = 2; i < N; i++){
        int max_sum = 0;
        if (i <= 6) {
            for (int j = 0; j < i; j++) {
                if (dp[j] > max_sum) {
                    max_sum = dp[j];
                }
            }
        }
        else {
            for (int j = i - 6; j < i; j++) {
                if (dp[j] > max_sum) {
                    max_sum = dp[j];
                }
            }
        }
        dp[i] = max_sum + A[i];
    }
    return dp[N-1];
}

int main() {
    int A[] = {1, -2, -3, 4, -3, 4, 5, 5};
    int N = 8;
    printf("Max path: %d\n", solution(A, N));
    return 0;
}