"""
Problem: Maximal Product of Any Triplet in an Array

Given a non-empty array A consisting of N integers, the goal is to find the maximal product 
of any triplet (P, Q, R) such that:
    - 0 ≤ P < Q < R < N
    - The product of a triplet is A[P] * A[Q] * A[R].

For example, given the array:
    A = [-3, 1, 2, -2, 5, 6]
The maximal product of any triplet is 60, from the triplet (2, 4, 5).

Assumptions:
    - N is between 3 and 100,000.
    - Each element in A is within the range [-1,000..1,000].

Approach:
1. Sort the array to efficiently find the largest and smallest elements.
2. The result can come from:
   - The product of the **three largest numbers**.
   - The product of the **two smallest numbers (negative) and the largest number**.

Time Complexity: O(N log N) due to sorting.
Space Complexity: O(1) since no extra space is used apart from a few variables.
"""

def solution(A):
    # sort array A
    quickSort(A, 0, len(A)-1)

    maxprod1 = maxprod2 = 0
    # 1. Max 3 elements (+, +, +)
    if A[-3] > 0:
        maxprod1 = A[-3]*A[-2]*A[-1]
    # 2. Max element & Min 2 elements (+, -, -)
    if A[1] < 0:
        maxprod2 = A[-1]*A[0]*A[1]
        
    return max(maxprod1, maxprod2)

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
A = [-3, 1, 2, -2, 5, 6]
print(solution(A))
# $ python max_product_three.py
# 60