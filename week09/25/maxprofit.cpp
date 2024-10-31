// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> &A) {
    // Edge case: 배열이 비어 있거나 요소가 하나뿐인 경우 이익을 얻을 수 없음
    if (A.size() < 2) return 0;

    int maxProfit = 0;
    int minPrice = A[0];

    for (size_t i = 1; i < A.size(); ++i) {
        // 각 날의 이익을 계산 (현재 가격 - 최소 구매 가격)
        int profit = A[i] - minPrice;

        // 최대 이익 업데이트
        maxProfit = max(maxProfit, profit);

        // 최소 구매 가격 업데이트
        minPrice = min(minPrice, A[i]);
    }

    return maxProfit;
}
