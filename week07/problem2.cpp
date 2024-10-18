class Solution
{
    public:
    void quickSort(int arr[], int low, int high)
    {
        // code here
        if (low<high){
            int pivot= partition(arr,low,high);
            quickSort(arr,low,pivot-1);
            quickSort(arr,pivot+1,high);
        }
    }
    
    int partition (int arr[], int low, int high)
    {
       // Your code here
       int pivot = arr[high];  
        int i = low - 1;       
    
        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;    
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);  
        return i + 1;   
       
    }
};