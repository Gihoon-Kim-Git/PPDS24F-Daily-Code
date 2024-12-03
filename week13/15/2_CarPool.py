import heapq
from typing import List

class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        trips.sort(key = lambda t: t[1])

        minHeap = []
        curpassenger = 0

        for trip in trips:
            passengerNum, start, end = trip
            while minHeap and minHeap[0][0] <= start:
                curpassenger -= minHeap[0][1] 
                heapq.heappop(minHeap)
            curpassenger += passengerNum
            if curpassenger > capacity:
                return False
            heapq.heappush(minHeap, [end, passengerNum])
        return True
        