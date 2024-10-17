// you can use includes, for example:
// #include <algorithm>
#include <algorithm>
#include <vector>

using namespace std;
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // Implement your solution here
    sort(A.begin(), A.end());
    int size = A.size();
    return max(A[0]*A[1]*A[size-1], A[size-1]*A[size-2]*A[size-3]);
}