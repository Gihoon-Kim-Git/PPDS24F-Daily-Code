class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        n = len(graph)
        # initialize color array, -1: not colored, 0 or 1: colored
        colors = [-1] * n

        # use BFS method
        for i in range(n):
            if colors[i] == -1:
                queue = deque([i])
                colors[i] = 0
                
                while queue:
                    node = queue.popleft()
                    current_color = colors[node]
                    next_color = 1 - current_color # 현재 노드의 색과 다른 색으로 설정: 1이면 0, 0이면 1로 처리

                    for neighbor in graph[node]:
                        if colors[neighbor] == -1:
                            colors[neighbor] = next_color
                            queue.append(neighbor)
                        elif colors[neighbor] == current_color:
                            return False
        return True
        