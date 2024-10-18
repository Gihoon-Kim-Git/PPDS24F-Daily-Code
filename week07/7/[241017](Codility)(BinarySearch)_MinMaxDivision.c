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

int solution(int K, int M, int A[], int N);

that, given integers K, M and a non-empty array A consisting of N integers, returns the minimal large sum.
*/

/*<constraint>
Write an efficient algorithm for the following assumptions:

N and K are integers within the range [1..100,000];
M is an integer within the range [0..10,000];
each element of array A is an integer within the range [0..M].*/

/*문제풀이
    1. isValidPartition(int K, max_sum, A[], N) : max_sum값을 가지도록 blocks를 만들었을 때, K개 이하로 만들 수 있는지 확인하는 함수.
        - A의 요소를 순회하면서, temp_sum을 관리. 만약 temp_sum > max_sum 되면 block 개수+1 & temp_sum은 0으로 리셋 & temp_sum += A[i] // else ㅅ드ㅔ_녀ㅡ += ㅁ[ㅑ]
        - 그렇게 만들어진 temp_sum 개수와 K를 비교해서 temp_sum > k 이면 return False. temp_sum = K 이면 return True

    2. solution(int K, int M, int A[], int N) : maxElement값이 M인 array A가 K blocks로 나누어졌을 때, 가질수 있는 minimal large sum 값 반환.
        - minimal large sum은 low, high 범위 내에서 움직인다.
        - 최초의 low (max_element 값), high(A의 모든 값 합)
        - while (low < high) 그동안 가능한 만큼 high를 낮추고, 필요하면 low는 높이면서 정답인 minimal large sum의 범위를 줄여나간다.(Binary search처럼 mid 값을 update 시키면서,)
            -- mid = (low + high)//2
            -- isValidPartition(K, mid, A, N) == true -> high를 mid값으로 바꿔줌.
                else -> low를 mid+1값으로 바꿔줌.
        - while문 탈출 ( low == high)일 때.. 그 때의 low 또는 high 값을 return. 
*/

#include <stdio.h>
#include <stdlib.h>

int isValidPartition(int K, int max_sum, int A[], int N){
    int current_K = 1;
    int temp_sum= 0;
    for (int i = 0; i < N; i++){
        if (temp_sum+A[i] > max_sum){
            current_K++;
            temp_sum = 0;
        }
        temp_sum += A[i];
    }

    if (current_K > K) return 0; // false
    else return 1; // true
}

int solution(int K, int M, int A[], int N){
    int low = 0;
    int high = 0;

    for (int i = 0; i < N; i++){
        high += A[i];
        if (low < A[i]) low = A[i];
    }

    int result = high;

    while (low <= high){
        int mid = (low + high)/2;

        if (isValidPartition(K,mid, A, N) == 1) {
            result = mid;
            high = mid-1;
        }
        else low = mid+1;
    }

    return result;
}

int main(){
    int Arr[] = {2,1,5,1,2,2,2};
    int N = 7;
    int K = 3;
    int M = 5;

    printf("%d", solution(K, M, Arr, N)); //6
}