from typing import List
from heapq import heappop, heappush

class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        # applying prim's algorithm
        # initialize edge node list
        N = len(points)
        adj = {i:[] for i in range(N)}
        for i in range(N):
            x1, y1 = points[i]
            for j in range(i+1, N):
                x2, y2 = points[j]
                dist = abs(x1-x2) + abs(y1-y2)
                adj[i].append((dist, j))
                adj[j].append((dist, i))
                
        ans = 0
        visited = set()
        cost_idx = [(0, 0)]
        # MST에서 edge의 길이는 N-1개
        while len(visited) < N:
            cost, idx = heappop(cost_idx)
            if idx in visited:
                continue
                
            visited.add(idx)
            ans += cost
            
            for nei in adj[idx]:
                if nei[1] not in visited:
                    heappush(cost_idx, nei)
                    
        return ans
    
sol = Solution()

points = [[2,-3],[-17,-8],[13,8],[-17,-15]]

print(sol.minCostConnectPoints(points))
