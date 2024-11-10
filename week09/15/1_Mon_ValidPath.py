from typing import List

class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        neighbors = [[] for _ in range(n)]
        for edge in edges:
            neighbors[edge[0]].append(edge[1])
            neighbors[edge[1]].append(edge[0])
            
        visited = [False] * n
        def help(node):
            visited[node] = True
            for neighbor in neighbors[node]:
                if not visited[neighbor]:                    
                    help(neighbor)
        help(source)
        return visited[destination]