// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <vector>
using namespace std;
int solution(vector<int> &A) {
    // Implement your solution here
    int n = A.size();
    vector<int> dp(n,0);
    dp[0] = A[0];

    for(int i=1;i<n;i++){
        int temp = dp[i-1];
        for(int j=2;j<=6;j++){
            if(i-j>=0){
                temp = max(temp,dp[i-j]);
            }
            else break;
        }
        dp[i] = temp + A[i];
    }
    return dp[n-1];
}
