#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> &A) {
    int N = A.size();
    vector<int> dp(N, -10001);  
    dp[0] = A[0];  

    for (int i = 1; i < N; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i - j >= 0) {  
                dp[i] = max(dp[i], dp[i - j] + A[i]);
            }
        }
    }

    return dp[N - 1];  
}