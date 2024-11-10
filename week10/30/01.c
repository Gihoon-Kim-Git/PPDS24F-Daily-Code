// 아하 DP 문제였규냐...
// 넘모 어려운걸


//(1). i~j까지의 min cost를 저장하는 dp table을 만든다. 0 초기화하고
//(2). 길이 2~n까지, 해서 모든 범위 참색해셔 start랑 end 고르고
//(2). start~end중에 하나 기준으로 뺴고 걔 + 이전 dp, 이후 dp 중 max인거 더해서 cost만들고
//(3). cost랑 원래 dp에 저장된 값이랑 min을 저장.
//(4). 마지막 return은 1~n까지 dp값으로

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// min 함수 정의
int min(int a, int b) {
    return (a < b) ? a : b;
}

// max 함수 정의
int max(int a, int b) {
    return (a > b) ? a : b;
}

int getMoneyAmount(int n) {
    // (1) DP 테이블을 생성하고 초기화
    int** dp = (int**)malloc((n + 1) * sizeof(int*));
    for (int i = 0; i <= n; i++) {
        dp[i] = (int*)malloc((n + 1) * sizeof(int));
        for (int j = 0; j <= n; j++) {
            dp[i][j] = 0; // 초기값을 0으로 설정합니다.
        }
    }

    // (2) 길이가 2 이상인 범위에 대해서 최적 비용을 계산
    for (int len = 2; len <= n; len++) {
        for (int start = 1; start <= n - len + 1; start++) {
            int end = start + len - 1;
            dp[start][end] = INT_MAX; // 초기값을 최대값으로 설정
            // 범위 [start, end]에서 가능한 모든 k 선택
            for (int k = start; k < end; k++) {
                int candidate = k + max(dp[start][k - 1], dp[k + 1][end]);
                dp[start][end] = min(dp[start][end], candidate); // 최소 비용 업데이트
            }
        }
    }

    int result = dp[1][n];

    // 동적 메모리 해제
    for (int i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
}


int main() {
    int n = 10;
    printf("ANSWER: %d\n", getMoneyAmount(n));
    return 0;
}
