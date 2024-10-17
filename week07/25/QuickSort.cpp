#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // code here
        if (low < high)
        {
            // Partitioning index, arr[pi] is now at the right place.
            int pi = partition(arr, low, high);

            // Recursively sort elements before partition and after partition
            quickSort(arr, low, pi - 1);  // Sort the left half
            quickSort(arr, pi + 1, high); // Sort the right half
        }
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       // Your code here
        int pivot = arr[high]; // Choose the last element as pivot
        int i = (low - 1); // Index of smaller element
        
        for (int j = low; j <= high - 1; j++)
        {
            // If current element is smaller than the pivot
            if (arr[j] < pivot)
            {
                i++; // Increment index of smaller element
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]); // Move pivot to the right place
        return (i + 1); // Return the partitioning index
    }
};

int main(void) {
    Solution a;
    int hello4[10] = {4,1,3,9,7,2,1};
    
    a.quickSort(hello4, 0, 5);
    for (int i=0; i<7; i++) {
        cout << hello4[i] << " ";
    }
    
    return 1;}