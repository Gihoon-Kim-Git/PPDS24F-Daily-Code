"""
<Pancake Sorting>
"""

def pancake_sort(arr):
    result = []
    n = len(arr)
    
    for size in range(n, 1, -1):
        # Find the index of the largest element in the unsorted portion
        max_idx = arr.index(max(arr[:size]))
        
        # If the largest element is not already in its correct position
        if max_idx != size - 1:
            # Step 1: Bring the largest element to the front if not already at the front
            if max_idx != 0:
                result.append(max_idx + 1)
                arr[:max_idx + 1] = reversed(arr[:max_idx + 1])
            
            # Step 2: Move it to its correct position
            result.append(size)
            arr[:size] = reversed(arr[:size])
    
    return result

arr = [3, 2, 4, 1]
k_values = pancake_sort(arr)
print("Pancake flip sequence:", k_values)
print("Sorted array:", arr)

arr = [1, 5, 4, 3, 2]
k_values = pancake_sort(arr)
print("Pancake flip sequence:", k_values)
print("Sorted array:", arr)
