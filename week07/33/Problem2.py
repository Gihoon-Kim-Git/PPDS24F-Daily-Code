# Quick Sort
# 강의자료 보고 코드만 파이썬으로 재현함

class Solution:
    #Function to sort a list using quick sort algorithm.
    def quickSort(self,arr,low,high):
        # code here
        if low < high:
            pivot = self.partition(arr, low, high)
            self.quickSort(arr, low, pivot-1)
            self.quickSort(arr, pivot+1, high)
    
    def partition(self,arr,low,high):
        # code here
        pivot = arr[high]   # pivot => 마지막 수
        i = low -1          # i => pivot보다 작은 것 중 가장 오른쪽 index
        for j in range(low, high):
            if arr[j] < pivot:
                i += 1
                # i와 i+1 사이가 pivot보다 크고 작은것 가르는 기준
                arr[i], arr[j] = arr[j], arr[i]     
        arr[i+1], arr[high] = arr[high], arr[i+1]
        return i+1