/*

You are given integers K, M and a non-empty array A consisting of N integers. Every element of the array is not greater than M.

You should divide this array into K blocks of consecutive elements. The size of the block is any integer between 0 and N. Every element of the array should belong to some block.

The sum of the block from X to Y equals A[X] + A[X + 1] + ... + A[Y]. The sum of empty block equals 0.

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
The goal is to minimize the large sum. In the above example, 6 is the minimal large sum.

Write a function:

int solution(int K, int M, int A[], int N);

that, given integers K, M and a non-empty array A consisting of N integers, returns the minimal large sum.

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
#include <stdio.h>
#include <limits.h> // 자료형의 최댓값과 최솟값이 정의된 헤더 파일
// Binary Search 로 분류된 문제 (+dp)
int countBlocks(int A[], int N, int maxSum)
{
  int blockCount = 1;
  int currentSum = 0;

  for (int i = 0; i < N; i++)
  {
    if (currentSum + A[i] > maxSum)
    {
      blockCount++;
      currentSum = A[i];
    }
    else
    {
      currentSum += A[i];
    }
  }

  return blockCount;
}

int solution(int K, int M, int A[], int N)
{
  int lowerBound = INT_MIN;
  int upperBound = 0;

  for (int i = 0; i < N; i++)
  {
    if (A[i] > lowerBound)
    {
      lowerBound = A[i];
    }
    upperBound += A[i];
  }

  int result = upperBound;

  while (lowerBound <= upperBound)
  {
    int mid = (lowerBound + upperBound) / 2;
    int blocks = countBlocks(A, N, mid);

    if (blocks <= K)
    {
      result = mid;
      upperBound = mid - 1;
    }
    else
    {
      lowerBound = mid + 1;
    }
  }

  return result;
}
