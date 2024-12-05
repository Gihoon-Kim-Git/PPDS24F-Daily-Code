# pancake sorting

from typing import List

class Solution:
    def pancakeSort(self, arr: List[int]) -> List[int]:
        # flip the array in place
        def flip(arr, k):
            arr[:k] = arr[:k][::-1]
        
        # finding the max index in a given subset
        def find_max(arr, n):
            max_index = 0
            for i in range(n):
                if arr[i] > arr[max_index]:
                    max_index = i
            return max_index
        
        result = []
        for i in range(len(arr), 1, -1):
            max_index = find_max(arr, i)

            #check if max_index is already in the correct position
            if max_index != i-1:
                if max_index != 0:

                    #max index is not the 1st index, flip to bring max_index to the front
                    result.append(max_index+1)
                    flip(arr, max_index+1)
                
                #flip again to put max index at the correct location
                result.append(i)
                flip(arr, i)

        return result

if __name__ == "__main__":
    sol = Solution()
    print(sol.pancakeSort([3,2,4,1]))
