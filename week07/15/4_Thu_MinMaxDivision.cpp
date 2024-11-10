// you can use includes, for example:
// #include <algorithm>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

bool can_divide(vector<int>& A, int K, int max_sum) {
    int count = 1;
    int current_sum = 0;
    for (int num : A) {
        if (current_sum + num > max_sum) {
            count++;
            current_sum = num;
            if (count > K) return false;
        } else current_sum += num;
    }
    return true;
}

int solution(int K, int M, vector<int> &A) {
    // Implement your solution here
    int low = *max_element(A.begin(), A.end());
    int high = accumulate(A.begin(), A.end(), 0);

    while (low <= high) {
        int mid = (low + high) / 2;
        if (can_divide(A, K, mid)) high = mid - 1;
        else low = mid + 1;        
    }
    return low;
}