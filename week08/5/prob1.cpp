// you can use includes, for example:
// #include <algorithm>
#include <vector>
using namespace std;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int K, vector<int> &A) {
    // Implement your solution here
    int ropesNum = 0;
    
    int currentSum = 0;
    for (int len : A) {
        // not enough length
        if (currentSum + len < K) currentSum += len;
        else {
            currentSum = 0;
            ropesNum += 1;
        }
    }

    return ropesNum;
}
