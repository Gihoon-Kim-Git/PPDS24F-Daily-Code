# week 07

## Tuesday. [Quick Sort](https://www.geeksforgeeks.org/problems/quick-sort/1)

#User function Template for python3

class Solution:
    #Function to sort a list using quick sort algorithm.
    def quickSort(self,arr,low,high):
        if low<high:
            pindex=self.partition(arr,low,high)
            self.quickSort(arr,low,pindex-1)
            self.quickSort(arr,pindex+1,high)
    def partition(self,arr,low,high):
        pivot=arr[low]
        i=low
        j=high
        while(i<j):
            while(i<high and arr[i]<=pivot):
                i+=1
            while(j>low and pivot<arr[j] ):
                j-=1
            if i<j:
                arr[i],arr[j]=arr[j],arr[i]
        arr[low],arr[j]=arr[j],arr[low]
        return j
    
