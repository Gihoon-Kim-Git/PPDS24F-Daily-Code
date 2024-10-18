#include <stdio.h>
#include <stdlib.h>

// QuickSort, divide and conquer

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