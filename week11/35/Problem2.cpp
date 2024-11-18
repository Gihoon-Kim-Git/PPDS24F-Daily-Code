/*
746. Min Cost Climbing Stairs

You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor

*/

// cost.size() -> top이라고 하자
// top에 올라가지까지 두 가지 방법 i-1, i-2에서 올라오는 방법, 둘 중 최소값 택하면 됨!

#include <iostream>
#include <vector>

using namespace std;

int minCostClimbingStairs(vector<int> &cost)
{
    // vector<int> Payment(cost.size()+1,0);
    // Payment[1] = cost[0];

    int n = cost.size();
    vector<int> Payment(n + 1, 0);

    for (int i = 2; i <= n; ++i)
    {
        Payment[i] = min(Payment[i - 1] + cost[i - 1], Payment[i - 2] + cost[i - 2]);
    }

    return Payment[n];

    return Payment.back();
}
