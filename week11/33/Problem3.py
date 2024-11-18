# point들의 좌표가 주어졌을 때 모든 point를 연결하는 path의 최소값
# 이 때, 거리는 manhattan distance 이용 

"""
stress test 통과 못함
"""
class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        costSum = 0
        visited = [0]
        unvisited = [i for i in range(1, n)]
        dist = [[-1] * n for _ in range(n)]

        while len(unvisited)!=0:
            minDist = -1
            for i in visited:
                for j in unvisited:
                    if dist[i][j] == -1:
                        dist[i][j] = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1])
                    if minDist == -1 or minDist > dist[i][j]:
                        minDist = dist[i][j]
                        visitPoint = j
            costSum += minDist
            visited.append(visitPoint)
            unvisited.remove(visitPoint)

        return costSum
    
"""
GPT 코드 -> min heap 이용
* heapq: 리스트의 min heap 특성 유지하며 method 실행
(관련 mehtod - heapify, heappush, heappop)
"""
import heapq

from typing import List

class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        costSum = 0
        visited = set()
        min_heap = [(0, 0)]  # (distance, point)
        
        while len(visited) < n:
            minDist, i = heapq.heappop(min_heap)
            if i in visited:
                continue
            
            costSum += minDist
            visited.add(i)
            
            for j in range(n):
                if j not in visited:
                    dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])
                    heapq.heappush(min_heap, (dist, j))
        
        return costSum
