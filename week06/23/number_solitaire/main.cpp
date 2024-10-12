#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int solution(vector<int> &A) {
    int N = A.size();

    // dp array to store the maximum sum at each square
    vector<int> dp(N, INT_MIN);
    dp[0] = A[0];  // The game starts at square 0

    // Iterate through the board to fill the dp array
    for (int i = 1; i < N; ++i) {
        // Look at up to 6 previous squares to get the max score
        for (int j = 1; j <= 6; ++j) {
            if (i - j >= 0) {
                dp[i] = max(dp[i], dp[i - j] + A[i]);
            }
        }
    }

    return dp[N - 1];  // Return the maximum result at the last square
}

int main() {
    vector<int> A = {1, -2, 0, 9, -1, -2};
    cout << solution(A) << endl;  // Output: 8
    return 0;
}
