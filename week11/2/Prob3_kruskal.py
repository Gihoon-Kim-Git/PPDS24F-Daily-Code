from typing import List

class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        # applying kruskal's algorithm
        # initialize parents table
        N =len(points)
        parent = [0] * (N+1)
        for i in range(1, N+1):
            parent[i] = i
        # find parent logic
        def find_parent(parent, x):
            if parent[x] != x:
                parent[x] = find_parent(parent, parent[x])
            return parent[x]
        
        # union logic
        def union_parent(parent, a, b):
            a = find_parent(parent, a)
            b = find_parent(parent, b)
            if a < b:
                parent[b] = a
            else:
                parent[a] = b
        
        # define edge list and total cost
        edges = []
        total_cost = 0

        # calculate edges cost
        for i in range(N):
            for j in range(N):
                if i == j:
                    continue
                edges.append((abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]), i, j))
        # sort by cost
        edges.sort()

        # use kruskal's algorithm
        for i in range(len(edges)):
            cost, a, b = edges[i]
            if find_parent(parent, a) != find_parent(parent, b):
                union_parent(parent, a, b)
                total_cost += cost
        
        
        return total_cost

        
sol = Solution()

points = [[2,-3],[-17,-8],[13,8],[-17,-15]]

print(sol.minCostConnectPoints(points))
