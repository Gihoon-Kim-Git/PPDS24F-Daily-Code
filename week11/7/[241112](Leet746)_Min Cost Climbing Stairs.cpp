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

#include <vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        for (int i= 2; i <= n-1;i++){
            int smaller_before = cost[i-1] < cost[i-2] ? cost[i-1] : cost[i-2];
            cost[i] = cost[i] +smaller_before;
        }

        return cost[n-1] < cost[n-2] ? cost[n-1] : cost[n-2];
    }
};