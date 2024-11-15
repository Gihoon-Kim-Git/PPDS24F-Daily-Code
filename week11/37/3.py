class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        min_cost = 0
        visited = set()
        priority_queue = [(0, 0)]
        
        while len(visited) < n:
            min_idx = 0
            for i in range(1, len(priority_queue)):
                if priority_queue[i][0] < priority_queue[min_idx][0]:
                    min_idx = i
            cost, i = priority_queue.pop(min_idx)

            if i in visited:
                continue
            visited.add(i)
            min_cost += cost

            for j in range(n):
                if j not in visited:
                    dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])
                    priority_queue.append((dist, j))

        return min_cost