from collections import List 

class Solution:
    def pancakeSort(self, arr: List[int]) -> List[int]:
        def flip(sub_k):
            nonlocal arr
            arr[:sub_k+1] = arr[:sub_k+1][::-1]

        k_values = []
        n = len(arr)
        for size in range(n, 1, -1):
            max_index = arr.index(max(arr[:size]))
            
            if max_index != size - 1:
                if max_index != 0:
                    flip(max_index)
                    k_values.append(max_index + 1)  

                flip(size - 1)
                k_values.append(size)  
        
        return k_values
