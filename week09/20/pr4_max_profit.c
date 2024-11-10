#include <stdio.h>

int solution(int A[], int N) {
    if (N < 2) return 0;

    int min_price = A[0];
    int max_profit = 0;

    for (int i = 1; i < N; i++) {
        // 최대 이익 갱신
        if (A[i] - min_price > max_profit) {
            max_profit = A[i] - min_price;
        }
        // 최소 가격 갱신
        if (A[i] < min_price) {
            min_price = A[i];
        }
    }
    
    return max_profit;
}

int main() {
    int A[] = {23171, 21011, 21123, 21366, 21013, 21367};
    int N = sizeof(A) / sizeof(A[0]);
    printf("Max Profit: %d\n", solution(A, N));
    return 0;
}
