#include <vector>
#include <algorithm>
#include <climits>

int solution(std::vector<int> &A) {
    int N = A.size();
    
    // DP 배열 생성, 처음에는 A[0]으로 초기화
    std::vector<int> dp(N, INT_MIN);
    dp[0] = A[0];
    
    // 각 칸에 대해 1~6칸 전에 도착할 수 있는 칸들 중에서 최대값을 찾음
    for (int i = 1; i < N; ++i) {
        // 이전 6칸 중에서 최대값을 찾음
        for (int dice = 1; dice <= 6; ++dice) {
            if (i - dice >= 0) {
                dp[i] = std::max(dp[i], dp[i - dice] + A[i]);
            }
        }
    }
    
    // 마지막 칸에서의 최대 점수 반환
    return dp[N - 1];
}
