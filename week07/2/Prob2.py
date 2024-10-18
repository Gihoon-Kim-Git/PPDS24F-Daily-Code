#User function Template for python3

class Solution:
    #Function to sort a list using quick sort algorithm.
    def quickSort(self,arr,low,high):
        # code here
        if len(arr) == 1:
            return arr
        
        if low < high:
            # pi: pivot value index(partitioning)
            pi = self.partition(arr, low, high)
            self.quickSort(arr, low, pi - 1)
            self.quickSort(arr, pi + 1, high)

        
    
    def partition(self,arr,low,high):
        # code here
        # pivot : last value of arr
        pivot = arr[high]
        i = low

        for j in range(low, high):
            # if current value is smaller than or equal to pivot
            if arr[j] <= pivot:
                arr[i], arr[j] = arr[j], arr[i]
                i += 1
        arr[i], arr[high] = arr[high], arr[i]
        return i
        
# Driver code starts, Initial template for Python 3
if __name__ == "__main__":
    t = int(input())
    for i in range(t):
        n = int(input())
        arr = list(map(int, input().split()))
        Solution().quickSort(arr, 0, n-1)
        for i in range(n):
            print(arr[i], end= " ")
        print()