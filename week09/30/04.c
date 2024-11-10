#include <stdlib.h>
#include <stdio.h>

int solution(int A[], int N) {
//combination을 다 보고! 그러면서 max를 유지하자.
//(1). 초기화
    int maxProfit = 0;

//(2). combination check
    for (int i = 0; i < N-1; i++) { //0부터 N-2까지
        for (int j = i+1; j < N; j++) {
            if (A[j] - A[i] > maxProfit) {
                maxProfit = A[j] - A[i];
            }
        }
    }
    return maxProfit;
}


int main() {
    int A[] = {23171, 21011, 21123, 21366, 21013, 21367};
    int N = sizeof(A) / sizeof(A[0]);

    int result = solution(A, N);
    printf("Result: %d\n", result);

    return 0;
}
