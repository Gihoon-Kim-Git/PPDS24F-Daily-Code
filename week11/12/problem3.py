import heapq
class Solution:
    
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        pq= []
        n = len(points)
        heapq.heappush(pq,(0,0))
        visited = [0]*n
        res=0
        while pq:
            cost, curr= heapq.heappop(pq)
            if visited[curr]:
                continue
            visited[curr]=1
            res+= cost
            for i in range(n):
                if not visited[i]:
                    dist= abs(points[curr][0]-points[i][0])+abs(points[curr][1]-points[i][1])
                    heapq.heappush(pq,(dist,i))
        return res
        