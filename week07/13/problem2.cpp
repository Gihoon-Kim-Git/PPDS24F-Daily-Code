#include <iostream>
#include <algorithm>
using namespace std;

class solution{
    public:
    // Function to sort an array using the quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if (low < high)
        {
            // Partition the array around pivot and get the pivot index
            int pivotIndex = partition(arr, low, high);

            // Recursively sort the elements before and after the partition
            quickSort(arr, low, pivotIndex - 1);
            quickSort(arr, pivotIndex + 1, high);
        }
    }
    
    public:
    int partition(int arr[], int low, int high)
    {
        // Choose the last element as the pivot
        int pivot = arr[high];
        int i = low - 1; // Index of the smaller element
        
        // i를 기준으로 왼쪽에 pivot보다 작은 값들이, i보다 큰쪽에 pivot보다 큰 값들이 모임
        // Rearrange the array based on the pivot
        for (int j = low; j < high; j++)
        {
            // If the current element is smaller than or equal to the pivot
            if (arr[j] <= pivot)
            {
                i++; // Increment the index of the smaller element
                std::swap(arr[i], arr[j]);
            }
        }

        // Place the pivot at its correct position
        std::swap(arr[i + 1], arr[high]);
        return i + 1; // Return the pivot index
    }
};

//문제 요구사항 pivot을 마지막 element로 할 것


//Quick sort
// 1. 피벗 선택: 배열에서 임의의 요소를 피벗으로 선택
// 일반적으로 첫 번째, 마지막 또는 중간 요소를 피벗으로 선택할 수 있음

// 2. 분할(Partition): 피벗을 기준으로 배열을 두 부분으로 나눕니다. 
// 피벗보다 작은 값들은 왼쪽 부분에, 피벗보다 큰 값들은 오른쪽 부분에 위치하게 됩니다. 
// 이 과정에서 배열의 요소들을 비교하고, 적절한 위치로 이동시킵니다.

// 3. 재귀적 호출: 피벗을 기준으로 나뉜 두 부분에 대해 다시 퀵 정렬을 재귀적으로 호출하여 정렬합니다.

// 4. 정렬 완료: 재귀 호출이 더 이상 불가능할 때(즉, 배열이 길이 1 이하가 될 때) 정렬이 완료됩니다.

