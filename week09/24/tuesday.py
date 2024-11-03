from typing import List
from collections import deque

class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        n = len(graph)
        color = [-1]*n #Initially all nodes are uncolored

        for i in range(n):
            if color[i] == -1 : #if a node is uncolored, implement BFS algo
                q = deque([i])
                color[i] = 0   # color the node with 0 (first color)
                while q :
                    node = q.popleft()
                    for nbour in graph[node]:
                        if color[nbour] == -1 :
                            color[nbour] = 1-color[node]
                            q.append(nbour)
                        elif color[nbour] == color[node]:
                            return False
        return True