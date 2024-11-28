# Car Pooling
from typing import List
import heapq

class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        heap = []
        for numPassengers, start, end in trips:
            heapq.heappush(heap, (start, numPassengers))
            heapq.heappush(heap, (end, -numPassengers))
        
        while capacity >= 0 and heap:
            capacity -= heapq.heappop(heap)[1]

        return len(heap) == 0