class Solution(object):
    def minCostConnectPoints(self, points):
        n = len(points)
        minDist = [float('inf')] * n
        mstSet = [False] * n
        minDist[0] = 0
        ans = 0
        for _ in range(n):
            u = -1
            for i in range(n):
                if not mstSet[i] and (u == -1 or minDist[i] < minDist[u]):
                    u = i
            mstSet[u] = True
            ans += minDist[u]
            for v in range(n):
                if not mstSet[v]:
                    dist = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1])
                    if dist < minDist[v]:
                        minDist[v] = dist
        return ans