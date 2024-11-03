#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

//4. max profit

#define max(X, Y) (X) > (Y)? (X):(Y)

int solution(int A[], int N) {
    int* arr = (int*)malloc(sizeof(int)*N);
    // int dp[N][2];
    // dp[0][0] = 0;
    // dp[0][1] = -A[0];
    int left = 0;
    int right = N-1;

    int i = 0;
    int max_num = 0;
    while (left < right) {
        if (A[right] > A[left]) {
            arr[i] = A[right] - A[left];
            left++;
            
        }

        else {
            left++;
        }
        i++;

    }
}