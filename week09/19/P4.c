#include <stdio.h>
#include <stdlib.h>

int solution(int* A, int N) {
    if (A == NULL || N == 0) return 0;
    int dp[N];
    for (int i=0; i<N; i++) dp[i] = 0;
    int minvalue = A[0];
    for (int j=1; j<N; j++) {
        minvalue = (minvalue > A[j] ? A[j] : minvalue);
        dp[j] = (A[j]-minvalue > dp[j-1] ? A[j]-minvalue : dp[j-1]);
    }
    return dp[N-1];
}

int main() {
    int A[] = {23171, 21011, 21123, 21366, 21013, 21367};
    printf("%d\n", solution(A, 6));

    return 0;
}