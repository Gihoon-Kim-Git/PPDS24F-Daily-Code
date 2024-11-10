class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        n = len(graph)

        colors = [0] * n

        for node in range(n):
            if colors[node] != 0:
                continue

            q = deque()
            q.append(node)
            colors[node] = 1

            while q:
                cur = q.popleft()

                for neighbor in graph[cur]:
                    if colors[neighbor] == 0:
                        colors[neighbor] = -colors[cur]
                        q.append(neighbor)
                    else:
                        if colors[neighbor] != -colors[cur]:
                            return False
        
        return True