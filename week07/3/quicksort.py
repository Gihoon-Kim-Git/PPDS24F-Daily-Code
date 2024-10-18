"""
Problem: Implement Quick Sort

Quick Sort is a Divide and Conquer algorithm that selects a 'pivot' element and partitions the array 
around the pivot such that:
    - All elements less than or equal to the pivot are on the left.
    - All elements greater than the pivot are on the right.

This process is repeated recursively to sort the entire array.

Expected Time Complexity: O(N * log N)
Expected Auxiliary Space: O(log N)

code ref. https://youtu.be/Vtckgz38QHs?si=2QSjZMGnTVL6O9HR
"""

# Function to perform quicksort on the array
def quickSort(arr, low, high):
    if low < high:
        # get pivot index through partitioning array
        pidx = partition(arr, low, high)

        # Recursion: apply quicksort to left and right partitions (excl. pivot)
        quickSort(arr, low, pidx - 1)
        quickSort(arr, pidx + 1, high)

# Function to partition the array using the last element as pivot
def partition(arr, low, high):
    # last element: pivot
    # other cases (first or middle element) possible
    pivot = arr[high]

    # i, j: pointer
    # j에 pivot보다 작은 값 경우 i의 값과 swap!
    i = low - 1
    # traversal through array
    for j in range(low, high):
        # compare each j element with pivot
        if arr[j] <= pivot:
            i += 1  # Increment index of smaller element
            arr[i], arr[j] = arr[j], arr[i]  # Swap
    
    # j: end of the array
    # i: the last element that is smaller or equal to the pivot
    # i+1: position where pivot element should be in
    arr[i + 1], arr[high] = arr[high], arr[i + 1]

    return i + 1  # pivot index

# Example Usage
arr = [4, 1, 3, 9, 7]
quickSort(arr, 0, len(arr) - 1)
print(arr)
# $ python quicksort.py
# [1, 3, 4, 7, 9]