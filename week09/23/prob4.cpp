#include <iostream>
#include <algorithm> // For std::min

int solution(const int A[], int N) {
    // If there are less than 2 days, no transaction can be made
    if (N < 2) return 0;

    int min_price = A[0];
    int max_profit = 0;

    for (int i = 1; i < N; i++) {
        // Update min_price using std::min
        min_price = std::min(min_price, A[i]);
        // Calculate profit if selling on the current day
        int profit = A[i] - min_price;
        // Update max_profit if the current profit is the best seen so far
        max_profit = std::max(max_profit, profit);
    }

    return max_profit;
}

int main() {
    // Example usage
    int A[] = {23171, 21011, 21123, 21366, 21013, 21367};
    int N = sizeof(A) / sizeof(A[0]);
    int result = solution(A, N);
    std::cout << "Maximum possible profit: " << result << std::endl;

    return 0;
}
