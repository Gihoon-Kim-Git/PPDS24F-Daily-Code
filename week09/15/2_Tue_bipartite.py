from collections import deque

class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        odd = [0] * len(graph)

        def bfs(node):
            if odd[node]:
                return True
            
            q = deque([node])
            odd[node] = -1
            while q:
                node = q.popleft()
                for neighbor in graph[node]:
                    if odd[node] == odd[neighbor]:
                        return False
                    elif not odd[neighbor]:
                        q.append(neighbor)
                        odd[neighbor] = -odd[node]
            return True
        
        for i in range(len(graph)):
            if not bfs(i):
                return False

        return True