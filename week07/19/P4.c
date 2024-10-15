#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool partition(int K, int mid, int A[], int N) {
    int temp = 0;
    int count = 1;
    for (int i=0; i<N; i++) {
        if (temp+A[i] <= mid) temp += A[i];
        else {
            count++;
            temp = A[i];
        }
    }
    if (count > K) return false;
    return true;
}

int solution(int K, int M, int A[], int N) {
    int upper = 0;
    for (int i=0; i<N; i++) upper += A[i];
    int lower = M;
    int result = upper;
    while (lower <= upper) {
        int mid = (upper + lower) / 2;
        if (partition(K, mid, A, N)) {
            result = mid;
            upper = mid - 1;
        } else lower = mid + 1;
    }
    return result;
}

int main() {
    int A[] = {2, 1, 5, 1, 2, 2, 2};
    int AN = sizeof(A)/sizeof(int);
    printf("%d\n", solution(3, 5, A, AN));

    int B[] = {5, 3};
    int BN = sizeof(B)/sizeof(int);
    printf("%d\n", solution(1, 10, B, BN));

    int C[] = {3, 4, 5, 6, 7, 8};
    int CN = sizeof(C)/sizeof(int);
    printf("%d\n", solution(4, 10, C, CN));

    return 0;
}