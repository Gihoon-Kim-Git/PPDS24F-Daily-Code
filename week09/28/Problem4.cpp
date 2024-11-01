#include <vector>

using namespace std;
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    if (A.size() < 2) {return 0;}

    int maxProfit = 0;
    int minPrice = A[0];  

    for (size_t i = 1; i < A.size(); ++i) {
        minPrice = min(minPrice, A[i]);
        int profit = A[i] - minPrice;
        maxProfit = max(maxProfit, profit);
    }

    return maxProfit;
}