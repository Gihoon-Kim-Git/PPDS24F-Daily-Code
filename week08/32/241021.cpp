// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int K, vector<int> &A) {
    // Implement your solution here
    int result = 0;
    int sum = 0;
    for (int i=0; i < A.size(); ++i) {
        sum += A[i];
        if (A[i] >= K) {
            result++;
            sum = 0;
        } else if (sum >= K) {
            result++;
            sum = 0;
        }
    }
    return result;
}