// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // Implement your solution here
    vector<int> dp(A.size(),0);
    dp[0] = A[0];

    for (int i=1; i < A.size(); ++i) {
        int m = dp[i-1];
        for (int j=2; j < 7; ++j) {
            if (i >= j) {
                m = max(m, dp[i-j]);
            }
        }
        dp[i] = m + A[i];
    }
    return dp[A.size()-1];
}