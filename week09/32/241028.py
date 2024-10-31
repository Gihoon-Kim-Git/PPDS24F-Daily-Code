class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        graph = {i : [] for i in range(n)}
        visited = set()
        q = deque()
        
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)
        q.append(source)

        while q:
            cur = q.popleft()

            if cur not in visited:
                visited.add(cur)

                for neighbor in graph[cur]:
                    if neighbor not in visited:
                        q.append(neighbor)

        return destination in visited