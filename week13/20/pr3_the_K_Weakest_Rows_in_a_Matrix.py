import heapq
from typing import List

class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        heap = []
        for i, row in enumerate(mat):
            heapq.heappush(heap, (row.count(1), i))
        return [heapq.heappop(heap)[1] for _ in range(k)]