from collections import List 

class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        # Helper function to calculate Manhattan distance
        def manhattan_distance(p1, p2):
            return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1])

        # Helper function to find the root of a set
        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])  # Path compression
            return parent[x]

        # Helper function to union two sets
        def union(x, y):
            rootX = find(x)
            rootY = find(y)
            if rootX != rootY:
                if rank[rootX] > rank[rootY]:
                    parent[rootY] = rootX
                elif rank[rootX] < rank[rootY]:
                    parent[rootX] = rootY
                else:
                    parent[rootY] = rootX
                    rank[rootX] += 1

        n = len(points)
        edges = []

        # Create all edges between points with their distances
        for i in range(n):
            for j in range(i + 1, n):
                dist = manhattan_distance(points[i], points[j])
                edges.append((dist, i, j))

        # Sort edges based on distance
        edges.sort()

        # Initialize DSU structure
        parent = list(range(n))
        rank = [0] * n

        # Kruskal's MST Algorithm
        result = 0
        num_edges_used = 0

        for dist, x, y in edges:
            if find(x) != find(y):
                union(x, y)
                result += dist
                num_edges_used += 1
                if num_edges_used == n - 1:
                    break

        return result