#include <algorithm>

int solution(vector<int> &A) {
    // Implement your solution here
    sort(A.begin(), A.end());

    int result = A[A.size()-1] * A[A.size()-2] * A[A.size()-3];

    int first = A[0] * A[1] * A[A.size()-1];
    if (first > result) {
        result = first;
    }
    return result;
}
