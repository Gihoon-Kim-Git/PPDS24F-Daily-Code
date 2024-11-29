# You are given an m x n binary matrix `mat` of 1's (representing soldiers) and 0's (representing civilians).
# The soldiers are positioned in front of the civilians, meaning all the 1's appear to the left of all the 0's in each row.
#
# A row i is weaker than a row j if:
# - The number of soldiers in row i is less than the number of soldiers in row j.
# - Both rows have the same number of soldiers, and i < j.
#
# Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.
#
# Example 1:
# Input: mat = [
#   [1, 1, 0, 0, 0],
#   [1, 1, 1, 1, 0],
#   [1, 0, 0, 0, 0],
#   [1, 1, 0, 0, 0],
#   [1, 1, 1, 1, 1]
# ], k = 3
# Output: [2, 0, 3]
#
# Example 2:
# Input: mat = [
#   [1, 0, 0, 0],
#   [1, 1, 1, 1],
#   [1, 0, 0, 0],
#   [1, 0, 0, 0]
# ], k = 2
# Output: [0, 2]
#
# Constraints:
# - 2 <= m, n <= 100
# - 1 <= k <= m
# - matrix[i][j] is either 0 or 1

def bubble_sort_custom(arr):
    """
    Custom bubble sort function to sort events. (ascending order)
    Sort by soldier numbers first, and if numbers are the same, sort by index.
    (soldier numbers in ascending, index in ascending)
    for descending, change like arr[j][1] > arr[j + 1][1]
    """
    n = len(arr)
    for i in range(n):
        for j in range(0, n - i - 1):
            if arr[j][1] > arr[j + 1][1] or (
                arr[j][1] == arr[j + 1][1] and arr[j][0] > arr[j + 1][0]
            ):
                # Swap arr[j] and arr[j + 1]
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

def kWeakestRows(mat, k):
    if len(mat) == 0:
        return []
    
    m = len(mat)
    n = len(mat[0])

    soldiers = []
    for i in range(m):
        curr_soldier = 0
        for j in range(n):
            if mat[i][j] == 1:
                curr_soldier += 1
        soldiers.append((i, curr_soldier))
    
    # print(soldiers)
    bubble_sort_custom(soldiers)

    ans = []
    for i in range(k):
        ans.append(soldiers[i][0])

    return ans

# Example test cases
def test_kWeakestRows():
    mat1 = [
        [1, 1, 0, 0, 0],
        [1, 1, 1, 1, 0],
        [1, 0, 0, 0, 0],
        [1, 1, 0, 0, 0],
        [1, 1, 1, 1, 1]
    ]
    k1 = 3
    print(kWeakestRows(mat1, k1))  # Output: [2, 0, 3]

    mat2 = [
        [1, 0, 0, 0],
        [1, 1, 1, 1],
        [1, 0, 0, 0],
        [1, 0, 0, 0]
    ]
    k2 = 2
    print(kWeakestRows(mat2, k2))  # Output: [0, 2]

test_kWeakestRows()