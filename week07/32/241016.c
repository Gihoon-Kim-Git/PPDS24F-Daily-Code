#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int solution(int A[], int N) {
    // Implement your solution here
    qsort(A, N, sizeof(int), compare);

    int result = A[N-1] * A[N-2] * A[N-3];

    int sub = A[0] * A[1] * A[N-1];

    if (sub > result) {
        result = sub;
    }
    return result;
}