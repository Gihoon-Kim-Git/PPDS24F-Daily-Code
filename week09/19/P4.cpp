#include <iostream>
using namespace std;

int solution(vector<int> A) {
    if (A.empty()) return 0;
    vector<int> dp(A.size(), 0);
    int minvalue = A[0];
    for (int i=1; i<A.size(); i++) {
        minvalue = min(minvalue, A[i]);
        dp[i] = max(A[i]-minvalue, dp[i-1]);
    }
    return dp[A.size()-1];
}

int main() {
    vector<int> A = {23171, 21011, 21123, 21366, 21013, 21367};
    cout << solution(A) << endl;

    return 0;
}