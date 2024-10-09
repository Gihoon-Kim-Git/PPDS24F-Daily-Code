// you can use includes, for example:
// #include <algorithm>
#include <cstddef>
#include <vector>
#include <climits>
using namespace std;
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // Implement your solution here

    // 문제 풀이 (점화식)
    // M(k) = M(k, N-1) : A[k] -> A[N-1] 일 때의 max sum
    // M(N-1) = A[N-1]
    // M(k) = max{ A[k] + M[k+i] } over i=1~6 and k+i<=N-1. 단, k < N-1

    // initial value : M[N-1]
    vector<int> maxSum(A.size(), INT_MIN);
    maxSum.back() = A.back();               // M[N-1] = A[N-1]

    // DP : top-down
    int N = A.size();
    for (int k = N-2; k >= 0; k--) {
        // M(k) = max{ A[k] + M[k+i] }
        int M = INT_MIN;
        for (int i=1; (i<7) && (k+i < N); i++) {
            if (A.at(k) + maxSum.at(k+i) > M) {
                M = A.at(k) + maxSum.at(k+i);
            }
        }
        maxSum.at(k) = M;
    }

    return maxSum.front();
}

// 문제 다 풀고 나서, 순간 greedy 로도 풀리는거 아닌가 했는데, 생각해보니 안된다.
// 처음에 생각했던 greedy algorithm : 양수인거 다 밟자, 6칸 이내 양수인게 없다면 음수 중에 젤 큰거 밟자
// - 반례 : (현재위치) [-1 -2 -3 -4 -5 -6] [-inf -inf -inf -inf -inf 1]
// - 실제로는 -6 -> 1 로 가는게 젤 낫지만
// - greedy는 -1 -2 -3 -4 -5 -6 을 모두 밟고 1 로 간다.

// 참고로, 0 -> N-1 과정의 maxSum 이나 N-1 -> 0 과정의 maxSum 이나 동일하므로 
// for loop 을 0부터 N-1까지 돌려도 결과는 같다.
