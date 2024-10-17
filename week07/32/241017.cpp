// you can use includes, for example:
#include <vector>
#include <algorithm>
#include <numeric>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

bool candivide(vector<int> &A, int K, int maxSum) {
    int currentSum = 0;
    int blocks = 1;

    for (int num : A) {
        if (currentSum + num > maxSum) {
            blocks++;
            currentSum = num;
            if (blocks > K) {
                return false;
            } 
        } else {
                currentSum += num;
        }
    }
    return true;
}

int solution(int K, int M, vector<int> &A) {
    // Implement your solution here
    int left = *max_element(A.begin(), A.end());
    int right = accumulate(A.begin(), A.end(), 0);

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (candivide(A, K, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}
