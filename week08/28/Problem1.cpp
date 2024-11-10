// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <vector>

using namespace std;

int solution(int K, vector<int> &A) {
    // Implement your solution here
    int count = 0;  
        int currentLength = 0;  
        for (int i = 0; i < A.size(); i++) {
            currentLength += A[i];  

            if (currentLength >= K) {
                count++;  
                currentLength = 0;  
            }
        }

        return count;  
}
