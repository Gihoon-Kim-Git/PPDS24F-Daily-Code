#include <stdio.h>
#include <stdlib.h>

// [1] qsort에 사용할 비교함수
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// [2] 최대 곱을 구하는 함수
int solution(int A[], int N) {
    // [2.1] 배열 정렬
    qsort(A, N, sizeof(int), compare);
    
    // [2.2] 세 개의 가장 큰 양수 또는 두 개의 가장 작은 음수와 가장 큰 양수의 곱 중 최대값을 계산
    int max1 = A[N-1] * A[N-2] * A[N-3];  // 배열의 끝에서 세 숫자의 곱
    int max2 = A[0] * A[1] * A[N-1];      // 가장 작은 두 음수와 가장 큰 양수의 곱

    // [2.3] 최대값을 반환
    return (max1 > max2) ? max1 : max2;
}

int main() {
    int A[] = {-3, 1, 2, -2, 5, 6};
    int N = sizeof(A) / sizeof(A[0]);
    
    int result = solution(A, N);
    
    printf("Max product of any triplet: %d\n", result);
    
    return 0;  
