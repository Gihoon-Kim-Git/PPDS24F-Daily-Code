class Solution:
    # Function to sort a list using the Quick Sort algorithm.
    def quickSort(self, arr, low, high):
        if low < high:
            # Partition the array and get the pivot index
            pi = self.partition(arr, low, high)
            
            # Recursively sort the elements before and after partition
            self.quickSort(arr, low, pi - 1)
            self.quickSort(arr, pi + 1, high)
    
    # Function to handle partitioning of the array
    def partition(self, arr, low, high):
        # Pivot is chosen to be the last element
        pivot = arr[high]
        i = low - 1  # Index of smaller element

        for j in range(low, high):
            # If current element is smaller than or equal to pivot
            if arr[j] <= pivot:
                i += 1
                arr[i], arr[j] = arr[j], arr[i]  # Swap elements
                
        # Place the pivot in the correct position
        arr[i + 1], arr[high] = arr[high], arr[i + 1]
        return i + 1
    