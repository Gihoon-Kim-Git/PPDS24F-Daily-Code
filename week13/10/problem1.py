from collections import List 
import heapq

class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        for i, s in enumerate(stones):
            stones[i] = -s
        
        heapq.heapify(stones)

        print(stones)
        while stones:
            s1 = -heapq.heappop(stones)
            if not stones:
                return s1
            s2 = -heapq.heappop(stones)
            if s1 > s2:
                heapq.heappush(stones, s2-s1)
        return 0