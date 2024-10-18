// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <vector>
#include <iostream>
#include <algorithm>  
#include <numeric>    

using namespace std;

bool Divide(vector<int>& A, int K, int maxBlockSum) {
    int blockCount = 1;  
    int currentSum = 0;

    for (int i = 0; i < A.size(); ++i) {
        if (currentSum + A[i] > maxBlockSum) {
            blockCount++;
            currentSum = A[i];
            if (blockCount > K) {
                return false;  
            }
        } 
        else {
            currentSum += A[i];
        }
    }
    return true;  
}

int solution(int K, int M, vector<int> &A) {
    // Implement your solution here
    int lowBound = *max_element(A.begin(), A.end());  
    int upBound = accumulate(A.begin(), A.end(), 0);  
    int result = upBound;  

    while (lowBound <= upBound) {
        int mid = (lowBound + upBound) / 2;

        if (Divide(A, K, mid)) {
            result = mid;  
            upBound = mid - 1;
        } 
        else {
            lowBound = mid + 1;  
        }
    }

    return result; 
}