#include <stdio.h>
#include <stdlib.h>

/*
MaxProductOfThree
A non-empty array A consisting of N integers is given. The product of triplet (P, Q, R) equates to A[P] * A[Q] * A[R] (0 ≤ P < Q < R < N).

For example, array A such that:

  A[0] = -3
  A[1] = 1
  A[2] = 2
  A[3] = -2
  A[4] = 5
  A[5] = 6
contains the following example triplets:

(0, 1, 2), product is −3 * 1 * 2 = −6
(1, 2, 4), product is 1 * 2 * 5 = 10
(2, 4, 5), product is 2 * 5 * 6 = 60
Your goal is to find the maximal product of any triplet.

Write a function:

int solution(int A[], int N);

that, given a non-empty array A, returns the value of the maximal product of any triplet.

For example, given array A such that:

  A[0] = -3
  A[1] = 1
  A[2] = 2
  A[3] = -2
  A[4] = 5
  A[5] = 6
the function should return 60, as the product of triplet (2, 4, 5) is maximal.
*/

int solution(int A[], int N)
{
    // dp 문제인가? 아니래!
    // sorting
    quickSort(A, 0, N - 1); // A가 sorting됨

    // 셋 다 음수일때 -> 제일 큰 숫자 세 개 곱하면 됨.
    // 둘 만 음수일때 A[N-1] > 0 - > 가장 작은 두 개의 숫자 * A[N-1]
    // 하나만 음수일때 A[N-3] < 0 - > A[0] * A[1] * A[N-1]

    // Calculate the maximum product of the three largest numbers
    int product1 = A[N - 1] * A[N - 2] * A[N - 3];
    
    // Calculate the maximum product of two smallest numbers and the largest number
    int product2 = A[0] * A[1] * A[N - 1];
    
    // Return the maximum of the two products
    return (product1 > product2) ? product1 : product2;
}

void Swap(int arr[], int idx1, int idx2)
{
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

void quickSort(int arr[], int low, int high)
{
    if (low <= high)
    {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

// pivot 인덱스 반환, low: arr의 시작 인덱스, high: arr의 마지막 인덱스
int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int left = low + 1;
    int right = high;

    while (left <= right)
    {
        // pivot보다 큰 값을 찾음
        while (pivot > arr[left])
        {
            left++;
        }

        // pivot보다 작은 값 찾음
        while (pivot < arr[right])
        {
            right++;
        }

        if (left <= right)
        {
            Swap(arr, left, right);
        }
    }

    // pivot과 high가 가리키는 값 교환
    Swap(arr, low, right);
    return right;
}

/*

bool isSubsequence(char* s, char* t) {
    int lenS = strlen(s);
    int lenT = strlen(t);
    int i = 0, j = 0;

    while (i < lenS && j < lenT) {
        if (s[i] == t[j]) {
            i++;
        }
        j++;
    }
    return i == lenS;
}

*/
