#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int numberSolitaire(int A[], int result, int N) {
    result += *A;
    int r1 = 0, r2 = 0, r3 = 0, r4 = 0, r5 = 0, r6 = 0;
    if (N > 1) r1 = numberSolitaire(&A[1], result, N - 1); // add 1
    if (N > 2) r2 = numberSolitaire(&A[2], result, N - 2); // add 2
    if (N > 3) r3 = numberSolitaire(&A[3], result, N - 3); // add 3
    if (N > 4) r4 = numberSolitaire(&A[4], result, N - 4); // add 4
    if (N > 5) r5 = numberSolitaire(&A[5], result, N - 5); // add 5
    if (N > 6) r6 = numberSolitaire(&A[6], result, N - 6); // add 6
    if (result < r1) result = r1;
    if (result < r2) result = r2;
    if (result < r3) result = r3;
    if (result < r4) result = r4;
    if (result < r5) result = r5;
    if (result < r6) result = r6;
    return result;
}

int solution1(int A[], int N) {
    int result = 0;
    if (*(A + N - 1) > 0) return numberSolitaire(A, result, N);
    return numberSolitaire(A, result, N) + *(A + N - 1);
}

int solution2(int A[], int N) {
    if (N == 1) return A[0];  // 도착점에 도달하면 그 값을 반환

    int result = INT_MIN;  // 매우 작은 값으로 초기화
    for (int dice = 1; dice <= 6; dice++) {
        if (N - dice > 0) {  // 배열 범위를 벗어나지 않도록 체크
            int temp = solution2(A, N - dice);  // 재귀 호출로 앞의 값들을 계산
            if (result < temp) {
                result = temp;  // 최대값 업데이트
            }
        }
    }
    
    return result + A[N - 1];  // 현재 칸의 값을 더해서 반환
}

int solution3(int A[], int N) {
    int dp[N];  // 각 칸에서 얻을 수 있는 최대 점수를 저장할 배열
    dp[0] = A[0];  // 첫 번째 칸의 점수는 A[0]과 같음

    // 각 칸에 도달할 수 있는 최대 점수를 계산
    for (int i = 1; i < N; i++) {
        dp[i] = INT_MIN;  // 매우 작은 값으로 초기화
        for (int dice = 1; dice <= 6; dice++) {
            if (i - dice >= 0) {  // i - dice가 범위 안에 있을 때만
                dp[i] = (dp[i] > dp[i - dice] + A[i]) ? dp[i] : (dp[i - dice] + A[i]);
            }
        }
    }

    return dp[N - 1];  // 마지막 칸에서의 최대 점수 반환
}

int main() {
    int A[] = {2, -3, 1, 9, 3, -1, 2, -4};
    
    printf("%d\n", solution1(A, sizeof(A)/sizeof(int)));
    printf("%d\n", solution2(A, sizeof(A)/sizeof(int)));
    printf("%d\n", solution3(A, sizeof(A)/sizeof(int)));

    return 0;
}