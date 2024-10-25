// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <vector>
using namespace std;

int solution(int K, vector<int> &A) {
    // Implement your solution here
    int result = 0;
    int cnt = 0;
    for(const int x : A){
        result += x;
        if(result >= K){
            cnt++;
            result = 0;
        }
    }
    return cnt;
}
