void quickSort(int arr[], int low, int high)
{
    // code here
    if (low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p-1);
        quickSort(arr, p+1, high);
    }
}
    
int partition (int arr[], int low, int high)
{
   // Your code here
    int pivot = arr[high];
    int idx = low;

    for (int i = low; i < high; i++) 
        if (arr[i] < pivot) {
            int temp = arr[i];
            arr[i] = arr[idx];
            arr[idx] = temp;
            idx++;
        }
    arr[high] = arr[idx];
    arr[idx] = pivot;
    return idx;
}