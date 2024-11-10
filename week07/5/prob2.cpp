#include <iostream>
using namespace std;

int partition (int arr[], int low, int high);

//Function to sort an array using quick sort algorithm.
void quickSort(int arr[], int low, int high)
{
    // code here
    // base case : no nothing
    if (low >= high);
    // recursive case
    else {
        int pivot = partition(arr, low, high);
        // cout << low << " " << pivot << " " << high << endl;
        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot+1, high);
    }
}
    
int partition (int arr[], int low, int high)
{
    // Your code here
    int pivot = high;
    int temp;
    for (int curr=low; curr<high; curr++) {
        if (curr < pivot) {
            if (arr[curr] > arr[pivot]) {
                temp = arr[curr];
                arr[curr] = arr[pivot];
                arr[pivot] = temp;
                pivot = curr;
            }
        } else {
            if (arr[curr] < arr[pivot]) {
                temp = arr[curr];
                arr[curr] = arr[pivot+1];
                arr[pivot+1] = arr[pivot];
                arr[pivot] = temp;
                pivot = pivot + 1;
            }
        }
    }
    return pivot;
}
