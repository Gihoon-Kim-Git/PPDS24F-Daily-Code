#include <stdio.h>
#include <math.h> // pow 함수를 사용하기 위한 헤더

int minimumOneBitOperations(int n) {
    if (n == 0) // 0일 경우 더이상 연산할 필요가 없어서 0 반환
        return 0;

    // 가장 왼쪽에서 켜져 있는 비트 위치를 찾습니다.
    int k = 0;
    while ((1 << k) <= n) // 1<<k는 2^k
        k++;
    k--;  // k는 가장 높은 비트 위치를 나타냅니다.

    // 연산의 결과는 `2^(k+1) - 1` 연산에서 재귀적으로 줄여 나가는 연산을 뺀 것입니다.
    // minimumOneBitOperations((1 << k) ^ n) : ((1 << k) ^ n)는 n에서 가장 높은 비트만 반전시킨 값
    return (int)(pow(2, k + 1) - 1) - minimumOneBitOperations((1 << k) ^ n);
}