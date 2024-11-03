from collections import deque
class Solution(object):
    def validPath(self, n, edges, source, destination):
        self.neighbors = {}
        for v in range(n):
            self.neighbors[v] = []
        for(v,w) in edges:
            self.neighbors[v].append(w)
            self.neighbors[w].append(v)
         
        visited = {}
        queue = deque() 
        for v in range(n):
            visited[v] = False

        if not visited[source]:
            queue.append(source)  
            visited[source] = True

            while queue:
                node = queue.popleft()
                if node == destination:
                    return True 

                
                for neighbor in self.neighbors[node]:
                    if not visited[neighbor]:
                        queue.append(neighbor)
                        visited[neighbor] = True
        return False