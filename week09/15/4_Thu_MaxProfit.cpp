// you can use includes, for example:
// #include <algorithm>
#include <algorithm>
#include <vector>

using namespace std;
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // Implement your solution here
    if (A.empty()) return 0;
    int min_price = A[0];
    int max_profit = 0;

    for (int price : A) {        
        min_price = min(price, min_price);
        int profit = price - min_price;
        max_profit = max(max_profit, profit);        
    }

    return max_profit;
}