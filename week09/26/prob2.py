class Solution(object):
    def isBipartite(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: bool
        """
        if len(graph) == 1:
            return True


        color = [None for _ in graph]
        for i in range(len(graph)):
            if color[i]:
                continue 
            to_visit = [i]
            color[i] = 1
            visited = []
            while to_visit:
                curr = to_visit.pop()
                visited.append(curr)
                for neighbor in graph[curr]:
                    if neighbor not in visited:
                        to_visit.append(neighbor)
                        if color[neighbor] is None:
                            color[neighbor] = -color[curr]
                        else:
                            if color[neighbor] == color[curr]:
                                return False
        return True