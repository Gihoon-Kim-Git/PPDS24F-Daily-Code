// you can use includes, for example:
#include <algorithm>
#include <vector>
using namespace std;
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // Implement your solution here
    int n = A.size();
    std::sort(A.begin(),A.end());

    return max(A[n-1]*A[n-2]*A[n-3],A[0]*A[1]*A[n-1]);

}
