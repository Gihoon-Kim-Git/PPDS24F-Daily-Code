#User function Template for python3

class Solution:
    #Function to sort a list using quick sort algorithm.
    def quickSort(self,arr,low,high):
        if high <= low:
            return 
        
        q = self.partition(arr, low, high)
        self.quickSort(arr, low, q)
        self.quickSort(arr, q+1, high)
            
    def partition(self,arr,low,high):
        pivot = low
        
        while low < high:
            while low < len(arr) and arr[low] <= arr[pivot]:
                low += 1  
            while high > 0 and arr[high] >= arr[pivot]:
                high -= 1
            if low <= high:
                arr[low], arr[high] = arr[high], arr[low]
                low += 1
                high -= 1
            else:
                arr[pivot], arr[low-1] = arr[low-1], arr[pivot]
        return low-1 
    
#User function Template for python3

class Solution_recursive:
    #Function to sort a list using quick sort algorithm.
    def quickSort(self,arr,low,high):
        if high - low < 1:
            return arr
        elif high - low == 1:
            if arr[low] > arr[high]:
                arr[low], arr[high] = arr[high], arr[low]
            return arr
        else:
            q = self.partition(arr, low, high)
            arr[low], arr[q] = arr[q], arr[low]
            pivot = arr[q]
            arr_left = self.quickSort(arr, low, q-1)[:q]
            arr_right = self.quickSort(arr, q+1, high)[q+1:]
            return arr_left + [pivot] + arr_right
            
    
    def partition(self,arr,low,high):
        pivot = arr[low]
        low = low + 1
        while low <= high:
            if arr[low] > pivot and arr[high] <= pivot:
                arr[low], arr[high] = arr[high], arr[low]
            if arr[low] <= pivot:
                low = low + 1
            if arr[high] > pivot:
                high = high - 1
        return low - 1
    

                
if __name__ == "__main__":
    arr = [4,1,3,9,7]
    print(Solution().quickSort(arr, 0, len(arr)-1))