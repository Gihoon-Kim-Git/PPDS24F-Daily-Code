#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int solution(int A[], int N)
{
    // marking된 A의 요소를 더해서 최대값이 되게 만드는게 목표임
    // 만약 marker + 주사위 수 > N - 1 이면, 다시 주사위 던짐
    // dp matrix 어케 만들지? A[N-1] + A[0] +...+ A[i] 값 중 최대값을 찾아야
    // 우선, A[N-1] + A[0] = sum 은 무조건 더해지는값, 현재 위치 j,그럼 sum + A[i] > sum && j + i < N-1, i에 marking, j = j + i;
    // sum = A[N-1] + A[0] + A[i]로 업데이트
    // dp
    // dp[0] = A[0], dp[1] = A[1] + dp[0], dp[2] = dp[0] + A[2] > dp[1] + A[2] ? dp[0] + A[2] : dp[1] + A[2]
    // dp[3] = dp[2] + A[3] > dp[0] + A[3]
    // 근데 i가 6보다 큰 경우도 고려해야,주사위로 1에서 6까지 이동할 수 있으므로
    // dp[i] = max(dp[i-1],dp[i-2],dp[i-3],dp[i-4],dp[i-5],dp[i-6]) + A[i]
    int dp[N];
    dp[0] = A[0];

    // dp[i]부터 채움
    for (int i = 1; i < N; i++)
    {
        int max_val = INT_MIN;
        for (int dice = 1; dice <= 6; dice++)
        {
            if (i - dice >= N)
            {
                if (dp[i - dice] > max_val)
                {
                    max_val = dp[i - dice];
                }
            }
        }
        dp[i] = max_val + A[i];
    }
    return dp[N - 1];
}