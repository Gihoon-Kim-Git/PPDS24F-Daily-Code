

class Solution(object):
    def isBipartite(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: bool
        """
        category = {}

        for i in range(len(graph)):
            if i not in category:
                category[i] = 0
                queue = [i]
                while queue:
                    current = queue.pop(0)
                    
                    for neighbor in graph[current]:
                        if neighbor not in category:
                            category[neighbor] = 1 - category[current]
                            queue.append(neighbor)
                        elif category[neighbor] == category[current]:
                            return False

        return True