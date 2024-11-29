from collections import List
import heapq

class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        heap = []
        for numPass, start, end in trips:
            heap.extend([(start, numPass), (end, -numPass)])
        heapq.heapify(heap)

        while capacity >= 0 and heap:
            capacity -= heapq.heappop(heap)[1]
        
        return len(heap) == 0