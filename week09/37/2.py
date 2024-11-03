class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        n = len(graph)
        color = [-1] * n

        def bfs(start):
            queue = [start]
            color[start] = 0
            
            while queue:
                node = queue.pop(0)
                for neighbor in graph[node]:
                    if color[neighbor] == -1:  # Not colored
                        color[neighbor] = 1 - color[node]  # Assign opposite color
                        queue.append(neighbor)
                    elif color[neighbor] == color[node]:  # Conflict in coloring
                        return False
            return True

        for i in range(n):
            if color[i] == -1:  # Not colored yet
                if not bfs(i):
                    return False

        return True
