def pancake_sort(arr):
    """
    Sort the array using pancake flips and return the sequence of k-values.
    """
    def flip(sub_arr, k):
        """Perform a pancake flip up to index k."""
        sub_arr[:k] = sub_arr[:k][::-1]

    res = []
    n = len(arr)

    for size in range(n, 1, -1):
        # Find the index of the maximum element within the current size
        max_index = arr.index(max(arr[:size]))

        if max_index != size - 1:
            # If the max element is not at its correct position, move it to the top
            if max_index != 0:
                # Flip to bring the max element to the top
                res.append(max_index + 1)
                flip(arr, max_index + 1)
            # Flip to move the max element to its correct position
            res.append(size)
            flip(arr, size)

    return res

# Example usage:
arr = [3, 2, 4, 1]
flips = pancake_sort(arr)

arr, flips  # Return the sorted array and the sequence of flips
