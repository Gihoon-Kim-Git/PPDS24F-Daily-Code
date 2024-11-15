#%%
#직접 sort하는 것보다 heapq쓰면 빠르다!
import heapq

class Solution:
    def minCostConnectPoints(self, points: list[list[int]]) -> int:
        connected = {0}
        hq = []
        cost = 0
        for i in range(1, len(points)):
            heapq.heappush(hq, (dist(points[0], points[i]), i))

        while hq and len(connected) < len(points):
            d, i = heapq.heappop(hq)
            if i not in connected:
                cost += d
                connected.add(i)
                for k in range(len(points)):
                    if k not in connected:
                        heapq.heappush(hq, (dist(points[i], points[k]), k))
        return cost
        
def dist(a, b):
    return abs(a[0] - b[0]) + abs(a[1] - b[1])




#%%
# 첫 시도
# Time limit
class Solution:
    def minCostConnectPoints(self, points: list[list[int]]) -> int:
        connected = [0]
        hq = []
        cost = 0
        for i in range(len(points)):
            hq.append((dist(points[0], points[i]), i))
        hq.sort()

        while hq:
            d,i = hq[0]
            if i not in connected:
                cost += d
                connected.append(i)
                for k in range(len(points)):
                    if k not in connected:
                        hq.append((dist(points[k], points[i]), k))
                hq.sort()
            else:
                hq = hq[1:]
        return cost
        
def dist(a, b):
    return abs(a[0] - b[0]) + abs(a[1] - b[1])
