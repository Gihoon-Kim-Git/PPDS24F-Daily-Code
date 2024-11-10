#include <stdio.h>

int solution(int A[], int N) {
    // If there are less than 2 days, no transaction can be made
    if (N < 2) return 0;

    int min_price = A[0];
    int max_profit = 0;

    for (int i = 1; i < N; i++) {
        // Update min_price if a new lower price is found
        if (A[i] < min_price) {
            min_price = A[i];
        }
        // Calculate profit if selling on the current day
        int profit = A[i] - min_price;
        // Update max_profit if the current profit is the best seen so far
        if (profit > max_profit) {
            max_profit = profit;
        }
    }

    return max_profit;
}

int main() {
    // Example usage
    int A[] = {23171, 21011, 21123, 21366, 21013, 21367};
    int N = sizeof(A) / sizeof(A[0]);
    int result = solution(A, N);
    printf("Maximum possible profit: %d\n", result);

    return 0;
}
