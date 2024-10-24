#include <stdio.h>
#include <stdlib.h>

int solution(int K, int A[], int N) {
    int count = 0, temp = 0;
    for (int i=0; i<N; i++) {
        if (temp+A[i] < K) temp += A[i];
        else {
            count++;
            temp = 0;
        }
    }
    return count;
}

int main() {
    int A[] = {1,2,3,4,1,1,3};
    printf("%d\n", solution(4, A, sizeof(A)/sizeof(int)));

    return 0;
}