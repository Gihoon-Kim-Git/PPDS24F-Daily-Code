from heapq import heappop, heappush

class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n

    def find(self, u):
        if self.parent[u] != u:
            self.parent[u] = self.find(self.parent[u])
        return self.parent[u]

    def union(self, u, v):
        rootU = self.find(u)
        rootV = self.find(v)
        if rootU != rootV:
            if self.rank[rootU] > self.rank[rootV]:
                self.parent[rootV] = rootU
            elif self.rank[rootU] < self.rank[rootV]:
                self.parent[rootU] = rootV
            else:
                self.parent[rootV] = rootU
                self.rank[rootU] += 1
            return True
        return False

def minCostConnectPoints(points):
    n = len(points)
    edges = []

    # Collect all edges and calculate Manhattan distances
    for i in range(n):
        for j in range(i + 1, n):
            dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])
            edges.append((dist, i, j))
    
    # Sort edges by distance
    edges.sort()
    uf = UnionFind(n)
    result = 0
    count = 0
    
    # Kruskal's Algorithm
    for dist, u, v in edges:
        if uf.union(u, v):
            result += dist
            count += 1
            if count == n - 1:
                break
    
    return result

# Example usage
points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
print("Minimum cost to connect points:", minCostConnectPoints(points))
