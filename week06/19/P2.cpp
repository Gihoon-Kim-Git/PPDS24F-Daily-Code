#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int solution1(vector<int> A) {
        int result = 0;
        if (*(A.end() - 1) > 0) return numberSolitaire(A, result);
        return numberSolitaire(A, result) + *(A.end() - 1);
    }

    vector<int> slice(vector<int> A, int a, int b) {
        return vector<int> (A.begin() + a, A.begin() + b);
    }

    int numberSolitaire(vector<int> A, int result) {
        result += A[0];
        int r1 = 0, r2 = 0, r3 = 0, r4 = 0, r5 = 0, r6 = 0;
        if (A.size() > 1) r1 = numberSolitaire(slice(A, 1, A.size()), result); // add 1
        if (A.size() > 2) r2 = numberSolitaire(slice(A, 2, A.size()), result); // add 2
        if (A.size() > 3) r3 = numberSolitaire(slice(A, 3, A.size()), result); // add 3
        if (A.size() > 4) r4 = numberSolitaire(slice(A, 4, A.size()), result); // add 4
        if (A.size() > 5) r5 = numberSolitaire(slice(A, 5, A.size()), result); // add 5
        if (A.size() > 6) r6 = numberSolitaire(slice(A, 6, A.size()), result); // add 6
        return max({result, r1, r2, r3, r4, r5, r6});
    }

    int solution2(vector<int> A) {
        if (A.size() == 1) return A[0];
        int result = INT_MIN;
        for (int dice = 1; dice <= 6; dice++) {
            if (A.size() > dice) {
                int temp = solution2(slice(A, 0, A.size() - dice));
                if (result < temp) {
                    result = temp;
                }
            }
        }
        return result + A[A.size() - 1];
    }

    int solution3(vector<int> A) {
        int dp[A.size()];
        dp[0] = A[0];
        for (int i = 1; i < A.size(); i++) {
            dp[i] = INT_MIN;
            for (int dice = 1; dice <= 6; dice++) {
                if (i - dice >= 0) {
                    dp[i] = (dp[i] > dp[i - dice] + A[i]) ? dp[i] : (dp[i - dice] + A[i]);
                }
            }
        }
        return dp[A.size() - 1];
    }
};

int main() {
    vector<int> A = {2, -3, 1, 9, 3, -1, 2, -4};
    
    Solution result;
    cout << result.solution1(A) << endl;
    cout << result.solution2(A) << endl;
    cout << result.solution3(A) << endl;

    return 0;
}