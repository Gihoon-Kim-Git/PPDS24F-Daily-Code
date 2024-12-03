import heapq
from typing import List

class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        h = []
        for stone in stones:
            heapq.heappush(h, -stone)   # heapq는 minheap

        while len(h) > 1:
            s1 = heapq.heappop(h)
            s2 = heapq.heappop(h)
            if s1 < s2:
                heapq.heappush(h, s1-s2)
        
        if len(h) > 0:
            return -h[0]
        else:
            return 0