#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int min(int x, int y) {
    return (x >= y) ? y : x; 
}
void print_1d_arr(int* arr, int arrSize) {
    for (int i = 0; i < arrSize; i ++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int dp_til_idx(int* cost, int costSize, int idx, int* dp) {
    if (dp[idx] != INT_MAX) {
        return dp[idx];
    }
    dp[idx] = min(dp_til_idx(cost, costSize, idx-1, dp) + cost[idx], 
                  dp_til_idx(cost, costSize, idx-2, dp) + cost[idx]);

    return dp[idx];
}

int minCostClimbingStairs(int* cost, int costSize) {

//(1). 저장할거 만들깅
    int* dp_table = (int*)malloc(costSize * sizeof(int));
    for (int i = 0; i < costSize; i++) {
        dp_table[i] = INT_MAX;
    }
//(2). base case
    dp_table[0] = cost[0];
    dp_table[1] = cost[1];
    dp_table[2] = min(cost[0]+cost[2], cost[1]);

//(3).
    int result = dp_til_idx(cost, costSize, costSize-1, dp_table);
    print_1d_arr(dp_table, costSize);
    free(dp_table);
    return result;
}


int main() {
    int cost1[] = {10, 15, 20};
    int cost2[] = {1, 100, 1, 1, 100, 1, 1, 100, 1};
                   
    int size1 = sizeof(cost1) / sizeof(cost1[0]);
    int size2 = sizeof(cost2) / sizeof(cost2[0]);

    printf("Answer 1: %d\n", minCostClimbingStairs(cost1, size1));
    printf("Answer 2: %d\n", minCostClimbingStairs(cost2, size2));
    
    return 0;
}