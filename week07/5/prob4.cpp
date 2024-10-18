// you can use includes, for example:
// #include <algorithm>
#include <vector>
using namespace std;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

bool divisibleWithBudget (int K, vector<int>& A, int budget);

int solution(int K, int M, vector<int> &A) {
    // Implement your solution here

    // solution 이 될 수 있는 값의 하한 : max(A)
    int low = A[0];
    for (int a : A) if (a > low) low = a;
    // solution 이 될 수 있는 값의 상한 : sum(A)
    int high = 0;
    for (int a : A) high += a;

    // binary search
    int sol = high;
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        // divisible with a budget : mid
        if (divisibleWithBudget(K, A, mid)) {
            sol = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return sol;
}

bool divisibleWithBudget (int K, vector<int>& A, int budget) {
    int currentSum = 0;
    int numBlocks = 1;
    for (int a : A) {
        // overflow
        if (currentSum + a > budget) {
            currentSum = a;
            numBlocks += 1;
            // un-divisibility detected
            if (numBlocks > K) {
                // cout << "(false) " << "budget : " << budget << endl;
                return false;
            }
        } else {
            currentSum += a;
        }
    }
    // cout << " (true) " << "budget : " << budget << endl;
    return true;
}