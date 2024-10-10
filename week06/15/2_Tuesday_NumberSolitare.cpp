// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int solution(vector<int> &A) {
    // Implement your solution here
    vector<int> dp(A.size(), INT_MIN);
    dp[0] = A[0];
    for(int i=0;i<A.size();i++) 
        for(int d=1; d<=6; d++) 
            if (i+d < A.size()) 
                dp[i+d] = max(dp[i+d], dp[i]+A[i+d]);
    return dp[A.size()-1];      
}