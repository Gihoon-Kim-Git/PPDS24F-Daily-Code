class Solution:
    def pancakeSort(self, arr: List[int]) -> List[int]:
        def flip(subarr, k):
            # Reverse the first k elements of the subarray
            subarr[:k] = subarr[:k][::-1]
        
        ans = []
        for i in range(len(arr), 1, -1):
            idx = max(range(i), key=lambda x: arr[x])
            
            if idx != i - 1:
                # Step 1: Flip the max element to the front
                if idx != 0:
                    flip(arr, idx + 1)
                    ans.append(idx + 1)
                
                # Step 2: Flip it to its correct position
                flip(arr, i)
                ans.append(i)

        return ans