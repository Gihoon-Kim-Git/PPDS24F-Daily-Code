/*<문제>
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

int solution(int K, int M, vector<int> &A);

that, given integers K, M and a non-empty array A consisting of N integers, returns the minimal large sum.
*/

/*<constraint>
Write an efficient algorithm for the following assumptions:

N and K are integers within the range [1..100,000];
M is an integer within the range [0..10,000];
each element of array A is an integer within the range [0..M].*/


#include <iostream>
#include <vector>
using namespace std;

int isValidPartition(int K, int max_sum, vector<int> &A){
    int current_K = 1;
    int temp_sum = 0;
    for (int a : A){
        if (temp_sum + a > max_sum){
            current_K++;
            temp_sum = a;
        }
        else temp_sum += a;
    }
    if (current_K > K) return 0;
    else return 1;
}

int solution(int K, int M, vector<int> &A){
    int low = 0;
    int high = 0;

    for (int a : A){
        high += a;
        if (a > low) low = a;
    }

    int result = high;

    while (low <= high){
        int mid = (low + high) / 2;
        if (isValidPartition(K, mid, A) == 1) {
            result = mid;
            high = mid-1;
        }
        else low = mid+1;
    }

    return result;
}