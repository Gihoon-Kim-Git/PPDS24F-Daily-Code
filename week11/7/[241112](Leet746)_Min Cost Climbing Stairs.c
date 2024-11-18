/*수도코드
1. dpT을 하나 만든다. cost와 같은 크기로.
    (Bottomup의 경우 cost를 그대로 쓰면서 update해도 되지만, 따로 하나 만드는 게 안전. )

2. 필요한 초기세팅
    n = len(cost)
    dpT[0] = cost[0]
    dpT[1] = cost[1]
    
3. 나머지 index (2 ~ n-1)에 대해서는 아래 점화식을 활용해 값을 update
    for i in range(2, n):
        dpT[i] = cost[i] + min(dpT[i-1], dpT[i-2])

4. 결과 반환
    RETURN min(dpT[n-2], dpT[n-1])
*/

#include <stdlib.h>

int minCostClimbingStairs(int* cost, int costSize) {
    int* dpT = (int*)malloc(sizeof(int)*costSize);

    dpT[0] = cost[0];
    dpT[1] = cost[1];

    for (int i = 2; i < costSize; i++){
        int one_before = dpT[i-1];
        int two_before = dpT[i-2];
        int smaller_cost = one_before < two_before ? one_before : two_before;
        dpT[i] = cost[i] + smaller_cost;
    }

    int answer = dpT[costSize-1] < dpT[costSize-2] ? dpT[costSize-1] : dpT[costSize-2];
    free(dpT);
    return answer;
}