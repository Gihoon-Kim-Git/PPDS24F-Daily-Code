// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include<vector>
using namespace std;

int solution(vector<int> &A) {
    // Implement your solution here
    if(A.empty()) return 0;

    int profit = 0;
    int temp_min = A[0];

    for(const int x : A){
        profit = max(profit,x-temp_min);
        temp_min = min(temp_min,x);
    }
    return profit;
}
