"""You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points"""

"""Minimum Spanning Tree 문제 : Kruskal 또는 prim으로 풀 수 있다. 나는 Kruskal로 품."""


# Kruskal 풀이
class DisjointSet:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n

    def find(self, u):
        if self.parent[u] != u:
            self.parent[u] = self.find(self.parent[u])  # Path compression
        return self.parent[u]

    def union(self, u, v):
        root_u = self.find(u)
        root_v = self.find(v)
        if root_u != root_v:
            # Union by rank
            if self.rank[root_u] > self.rank[root_v]:
                self.parent[root_v] = root_u
            elif self.rank[root_u] < self.rank[root_v]:
                self.parent[root_u] = root_v
            else:
                self.parent[root_v] = root_u
                self.rank[root_u] += 1


class Solution(object):
    def kruskal(self, n, edges):
        dsu = DisjointSet(n)
        mst = []
        edges.sort(key=lambda x: x[2])  # Sort edges by weight
        
        for u, v, weight in edges:
            if dsu.find(u) != dsu.find(v):
                dsu.union(u, v)
                mst.append((u, v, weight))
        
        return mst

    #//절댓값(맨해튼 거리) 계산용으로 만든 함수
    def make_edge_point_index(self, i, j, points) :
        p1 = points[i]
        p2 = points[j]
        
        w_x = p1[0]-p2[0]
        w_y = p1[1]-p2[1]
        w_x = -w_x if w_x < 0 else w_x
        w_y = -w_y if w_y < 0 else w_y
        
        w = w_x + w_y
        
        return (i, j, w)
    
    def minCostConnectPoints(self, points):
        edges = []
        points_len = len(points)
        for i in range(points_len):
            for j in range(points_len):
                if i != j:
                    edges.append(self.make_edge_point_index(i, j, points))
        
        mst_edges = self.kruskal(points_len, edges)
        
        sum = 0
        for i in range(len(mst_edges)):
            sum += mst_edges[i][2]
        
        return sum
    
    
# Prim 풀이 참고.
import heapq
class Solution:
    def minCostConnectPoints(self, points):
        n = len(points)
        # for simplicity, marking the points with a node value from 0 to (n-1)
        adjList = {i:[] for i in range(n)}  # key = curr node, value = (dist, other nodes)
        for i in range(n):
            x1 = points[i][0]; y1 = points[i][1]
            for j in range(i+1, n):
                x2 = points[j][0]; y2 = points[j][1]
                dist = abs(x1 - x2) + abs(y1 - y2)
                # as it is a undirected graph, we need to add both i and j to adjList
                adjList[i].append((dist, j))
                adjList[j].append((dist, i))
        
        # Prim's Algorithm - Minimum Spanning Tree (MST) 
        # (In the Dijkstra's Algorithm if we introduce a visited data structure to 
        # stop cycle in graph then it converts to Prim's Algorithm)
        visited = set()
        res = 0
        minHeap = [(0, 0)]  # (dist, node)
        while len(visited) < n: # until all nodes a visited
            dist, node = heapq.heappop(minHeap)
            if node in visited: continue
            visited.add(node)
            res += dist
            for dn in adjList[node]:  # dn = (dist, node)
                if dn[1] not in visited:
                    heapq.heappush(minHeap, dn)
        
        return res


# V = number of umber of verices and E = numver of Edges in the graph.
# Time: O(V^2) + O((V+E)logV) = O(V^2)
# Space: O(V^2)  In worst cases all connections of undirected graph can be in minheap 