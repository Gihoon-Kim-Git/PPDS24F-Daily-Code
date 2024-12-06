from typing import List

class Solution:
    def pancakeSort(self, arr: List[int]) -> List[int]:
        res = []
        for target in range(len(arr), 1, -1):
            idx = arr.index(target)             # idx는 arr 내에서 target의 index 
            res.extend([idx + 1, target])
            arr = arr[:idx:-1] + arr[:idx]
        return res