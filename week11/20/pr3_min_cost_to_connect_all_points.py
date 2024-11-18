from heapq import heappop, heappush
from typing import List

class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        if n <= 1:
            return 0

        # 맨해튼 거리 계산 함수
        def manhattan(point1, point2):
            return abs(point1[0] - point2[0]) + abs(point1[1] - point2[1])

        ans = 0
        min_heap = [(0, 0)]  # (cost, point index)
        in_mst = [False] * n
        edges_used = 0

        while edges_used < n:
            cost, u = heappop(min_heap)
            if in_mst[u]:
                continue
            
            # 현재 점을 MST에 추가
            in_mst[u] = True
            ans += cost
            edges_used += 1

            # 새로운 점에서 다른 점들까지의 비용을 계산하고 힙에 추가
            for v in range(n):
                if not in_mst[v]:
                    heappush(min_heap, (manhattan(points[u], points[v]), v))

        return ans
