// you can use includes, for example:
#include <algorithm>
#include<vector>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // Implement your solution here
    sort(A.begin(), A.end());
    
    int n = A.size();
    
    int max1 = A[n-1] * A[n-2] * A[n-3];
    
    int max2 = A[0] * A[1] * A[n-1];
    
    return max(max1, max2);
}