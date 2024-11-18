"""
<Min cost to connect all points>

You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.
"""

import heapq

def minCostConnectPoints(points):

    n = len(points)
    if n==1: return 0

    # Prim's algorithm (greedy)
    min_cost = 0
    min_heap = [(0,0)]    # (cost, node index)
    visited = set()
    edges = 0

    while edges < n:
        cost, i = heapq.heappop(min_heap)     # 이전 노드에서 연결하는 cost가 가장 적은 애들부터 pop 됨
        if i in visited:
            continue
        min_cost += cost
        visited.add(i)
        edges += 1

        for j in range(n):
            if j not in visited:
                manhattan_distance = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1])
                heapq.heappush(min_heap, (manhattan_distance,j))

    return min_cost

print(minCostConnectPoints([[0,0],[2,2],[3,10],[5,2],[7,0]]))  # 20
print(minCostConnectPoints([[3,12],[-2,5],[-4,1]]))  # 18