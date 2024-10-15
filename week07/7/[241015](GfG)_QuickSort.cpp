/* <QuickSort>
    1. quickSort : arr[low:high]를 Sort한 후, 분류가 끝난 pivot의 좌-list, 우-list 각각으로 나누어주는 과정. 
        base case : 더이상 divde하지 않는 과정 (길이가 0 || 1)
        recursive :
            left : arr[low:pivot_done]
            right : arr[pivot_done+1 : high]
    2. partition( : arr[low:high] 구간을 pivot을 기준으로 정렬하는 함수
        : 1) last element를 pivotValue로 설정. : arr[high]
        : 2) i, j를 활용한 sort. pivot 좌측은 작은값, pivot 우측은 큰 값.
                i : pivot보다 작은 요소들의 위치
                j : low~high-1 까지를 순회하는 역할
                만약  arr[j] <= pivotValue  :   arr[i], arr[j] swap, 그리고 i++
        : 3) pivotValue 위치를 좌/pivot/우 사이로 옮겨줌.(arr[i+1]와 swap)
        : 4) return high; (pivotValue가 현재 위치한 index)

*/

#include <iostream>
using namespace std;

class Solution{
    public:
    void quickSort(int arr[], int low, int high){
        if (low < high) {
            int pivot_done = partition(arr, low, high);
            quickSort(arr, low, pivot_done-1);
            quickSort(arr,pivot_done+1, high);
        }
    }
    public:
    int partition(int arr[], int low, int high){
        //1) 
        int pivotValue = arr[high];
        int i = low;

        //2)
        for (int j = low; j < high; j++){
            if (arr[j] <= pivotValue){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;

                i++;
            }
        }

        //3
        int temp2 = arr[i];
        arr[i] = pivotValue;
        arr[high] = temp2; // arr[i]값을 기존 pivotValue가 위치했던 자리로.

        //4
        return i;
    }
};