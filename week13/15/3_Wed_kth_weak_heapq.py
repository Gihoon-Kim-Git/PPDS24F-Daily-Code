import heapq
from typing import List

class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        h = []
        for i, row in enumerate(mat):
            s = 0
            while s < len(row) and row[s] == 1: 
                s += 1
            heapq.heappush(h, (s, i))

        res = []
        for i in range(k):
            weakest =  heapq.heappop(h)
            res.append(weakest[1])
        
        return res

        