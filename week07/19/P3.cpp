#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int a, int b) {
    return a > b;
}

class Solution {
public:
    int solution(vector<int> A) {
        sort(A.begin(), A.end(), compare);
        if (A[0] * A[1] * A[2] > A[0] * A[A.size()-1] * A[A.size()-2]) {
            return A[0] * A[1] * A[2];
        }
        return A[0] * A[A.size()-1] * A[A.size()-2];
    }
};

int main() {
    vector<int> A = {-7, 1, 2, -4, 5, 6};

    Solution result;
    cout << result.solution(A) << endl;

    return 0;
}