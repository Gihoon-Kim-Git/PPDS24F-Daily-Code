// you can use includes, for example:
// #include <algorithm>
#include <vector>
using namespace std;
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int K, vector<int> &A) {
    // Implement your solution here
    int count = 0;
        int length = 0;
        for(int rope : A) {
            length += rope;
            if (length >= K) { 
                count++;
                length = 0;
            }
        }
        return count;
}