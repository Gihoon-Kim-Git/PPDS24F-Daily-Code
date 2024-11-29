from heapq import nsmallest

def kWeakestRows(mat, k):
    # Calculate the strength of each row
    strengths = []
    for i, row in enumerate(mat):
        soldier_count = sum(row)  # Count 1's in the row
        strengths.append((soldier_count, i))
    
    # Sort by strength (first key) and index (second key)
    strengths.sort()
    
    # Extract the indices of the k weakest rows
    return [strengths[i][1] for i in range(k)]

# Example usage
mat = [
    [1, 1, 0, 0, 0],
    [1, 1, 1, 1, 0],
    [1, 0, 0, 0, 0],
    [1, 1, 0, 0, 0],
    [1, 1, 1, 1, 1]
]
k = 3
print(kWeakestRows(mat, k))  # Output: [2, 0, 3]
