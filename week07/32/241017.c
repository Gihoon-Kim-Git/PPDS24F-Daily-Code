#include <stdio.h>
#include <stdlib.h>

int canDivide(int *A, int N, int K, int maxSum) {
    int currentSum = 0;
    int blocks = 1;

    for (int i = 0; i < N; i++) {
        if (currentSum + A[i] > maxSum) {
            blocks++;
            currentSum = A[i];
            if (blocks > K) {
                return 0;
            }
        } else {
            currentSum += A[i];
        }
    }
    return 1;
}

int solution(int K, int M, int *A, int N) {
    int left = 0, right = 0;

    for (int i = 0; i < N; i++) {
        if (A[i] > left) {
            left = A[i];
        }
        right += A[i];
    }

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (canDivide(A, N, K, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

