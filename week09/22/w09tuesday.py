class Solution(object):
    def isBipartite(self, graph):

        n = len(graph)
        color = [-1] * n

        for i in range(n):
            if color[i] == -1:
                queue = [i]
                color[i] = 0

                while queue:
                    node = queue.pop(0)
                    for neighbor in graph[node]:
                        if color[neighbor] == -1:
                            color[neighbor] = 1 - color[node]  
                            queue.append(neighbor)
                        elif color[neighbor] == color[node]:
                            return False

        return True