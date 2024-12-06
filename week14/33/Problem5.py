class Solution:
    def pancakeSort(self, arr: List[int]) -> List[int]:
        def flip(subarr, k):
            """Reverse the first k elements of subarr."""
            subarr[:k] = subarr[:k][::-1]

        n = len(arr)
        result = []

        for size in range(n, 1, -1):
            # Find the index of the maximum value in arr[0:size]
            max_index = arr.index(max(arr[:size]))

            # Bring the maximum value to the front if it is not already there
            if max_index != 0:
                result.append(max_index + 1)  # Flip to bring the max to the front
                flip(arr, max_index + 1)
            
            # Now flip the entire current size to bring the maximum to its sorted position
            result.append(size)
            flip(arr, size)

        return result
