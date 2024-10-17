/*
You are given integers K, M and a non-empty array A consisting of N integers.
Every element of the array is not greater than M.

You should divide this array into K blocks of consecutive elements. The size of
the block is any integer between 0 and N. Every element of the array should
belong to some block.

The sum of the block from X to Y equals A[X] + A[X + 1] + ... + A[Y]. The sum of
empty block equals 0.

The large sum is the maximal sum of any block.

For example, you are given integers K = 3, M = 5 and array A such that:

  A[0] = 2
  A[1] = 1
  A[2] = 5
  A[3] = 1
  A[4] = 2
  A[5] = 2
  A[6] = 2
The array can be divided, for example, into the following blocks:

[2, 1, 5, 1, 2, 2, 2], [], [] with a large sum of 15;
[2], [1, 5, 1, 2], [2, 2] with a large sum of 9;
[2, 1, 5], [], [1, 2, 2, 2] with a large sum of 8;
[2, 1], [5, 1], [2, 2, 2] with a large sum of 6.
The goal is to minimize the large sum. In the above example, 6 is the minimal
large sum.

Write a function:

int solution(int K, int M, vector<int> &A);
that, given integers K, M and a non-empty array A consisting of N integers,
returns the minimal large sum.

For example, given K = 3, M = 5 and array A such that:

  A[0] = 2
  A[1] = 1
  A[2] = 5
  A[3] = 1
  A[4] = 2
  A[5] = 2
  A[6] = 2
the function should return 6, as explained above.

Write an efficient algorithm for the following assumptions:

N and K are integers within the range [1..100,000];
M is an integer within the range [0..10,000];
each element of array A is an integer within the range [0..M].
*/
#include <cassert>
#include <cmath>
#include <cstdbool>
#include <numeric>
#include <vector>

using namespace std;

bool IsUnderTargetSum(int target, int K, const vector<int>& A) {
  int n = A.size();
  int i = 0;
  for (int g = 0; g < K; ++g) {
    int cur_sum = 0;
    while (i < n) {
      int x = A[i];
      if (cur_sum + x <= target) {
        cur_sum += x;
        ++i;
      } else {
        break;
      }
    }
    if (g == K - 1 && i < n) return false;
  }
  return true;
}

int solution(int K, int M, vector<int>& A) {
  int min_sum = 0;
  int max_sum = accumulate(A.begin(), A.end(), 0);
  while (min_sum <= max_sum) {
    int target = floor((min_sum + max_sum) / 2);
    if (IsUnderTargetSum(target, K, A)) {
      max_sum = target - 1;
    } else {
      min_sum = target + 1;
    }
  }
  return min_sum;
}

int main() {
  vector<int> arr{2, 1, 5, 1, 2, 2, 2};
  assert(solution(3, 5, arr) == 6);
  vector<int> arr2{0};
  assert(solution(1, 1, arr2) == 0);
}
