#include <stdio.h>

// Problem Summary:
// Given an array A of N ropes, where each element represents the length of a rope, 
// and an integer K, the goal is to tie adjacent ropes together in such a way that 
// the number of ropes with a length greater than or equal to K is maximized.
// Two adjacent ropes can be tied together, and the resulting rope's length is the 
// sum of their lengths. The problem is to find the maximum number of ropes that 
// can be tied to achieve lengths greater than or equal to K.

int solution(int K, int A[], int N) {
    int ans = 0; // number of ropes w. length >= K

    int curr_length = 0; // accumulated length of current tied rope

    for (int i=0; i < N; i++) {
        curr_length += A[i]; // A[i]: rope length

        if (curr_length >= K) {
            ans++;

            // RESET CURRENT LENGTH (GREEDY APPROACH)
            curr_length = 0; // consider next ropes separately
            // form smallest possible valid rope segment before adding next rope
            // maximize number of segments: remaining ropes are carrired forward
        }
    }

    return ans;
}

// Example usage
int main() {
    int K = 4;
    int A[] = {1, 2, 3, 4, 1, 1, 3};
    int N = sizeof(A) / sizeof(A[0]);

    int result = solution(K, A, N);
    printf("%d\n", result);  // 3

    return 0;
}