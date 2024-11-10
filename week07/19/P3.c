#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b) {
    return *(int*)b - *(int*)a;
}

int solution(int A[], int N) {
    qsort(A, N, sizeof(int), compare);
    if (A[0] * A[1] * A[2] > A[0] * A[N-1] * A[N-2]) {
        return A[0] * A[1] * A[2];
    }
    return A[0] * A[N-1] * A[N-2];
}

int main() {
    int A[] = {-7, 1, 2, -4, 5, 6};
    int N = sizeof(A)/sizeof(int);
    printf("%d\n", solution(A, N));

    return 0;
}