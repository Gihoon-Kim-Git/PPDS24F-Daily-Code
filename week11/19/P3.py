import heapq ## priority queue

class Solution1(object): ## Kruskal
    def minCostConnectPoints(self, points):
        edges = []
        for i in range(len(points)):
            for j in range(i+1, len(points)):
                dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])
                edges.append((dist, i, j))
        
        edges.sort()
        
        parent = list(range(len(points)))

        def find(v):
            if parent[v] != v:
                parent[v] = find(parent[v])
            return parent[v]

        def union(v, w):
            root_v = find(v)
            root_w = find(w)
            if root_v != root_w:
                parent[root_w] = root_v
                return True
            return False
        
        min_cost = 0
        edge_count = 0

        for dist, u, v in edges:
            if union(u, v):
                min_cost += dist
                edge_count += 1
                if (edge_count == len(points) - 1):
                    break

        return min_cost
        
class Solution2(object): ## Prim
    def minCostConnectPoints(self, points):
        n = len(points)

        visited = [False] * n
        min_heap = [(0, 0)]
        min_cost = 0
        edges = 0

        while edges < n:
            cost, u = heapq.heappop(min_heap)

            if visited[u]:
                continue

            visited[u] = True
            min_cost += cost
            edges += 1

            for v in range(n):
                if not visited[v]:
                    dist = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1])
                    heapq.heappush(min_heap, (dist, v))
        
        return min_cost

if __name__ == "__main__":
    # result = Solution1()
    result = Solution2()
    points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
    print(result.minCostConnectPoints(points))
    points = [[3,12],[-2,5],[-4,1]]
    print(result.minCostConnectPoints(points))