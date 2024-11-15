int min(int a, int b) {
    return (a < b) ? a : b;
}

int minCostClimbingStairs(int* cost, int costSize) {
    int arr[costSize+1];

    arr[0] = 0;
    arr[1] = 0;

    for (int i=2; i < costSize+1; i++) {
        arr[i] = min(arr[i-1] + cost[i-1], arr[i-2] + cost[i-2]);
    }
    return arr[costSize];
}