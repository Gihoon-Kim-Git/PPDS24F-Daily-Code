class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        # make neighbor list
        neighbors = dict()
        for n1, n2 in edges:
            if neighbors.get(n1, False):
                neighbors[n1].append(n2)
            else:
                neighbors[n1] = [n2]
            if neighbors.get(n2, False):
                neighbors[n2].append(n1)
            else:
                neighbors[n2] = [n1]
                


        
        # define BFS    
        q = deque([source])
        visited = set([source])
        while q:
            node = q.popleft()            
            if node == destination:
                return True            
            for n in neighbors[node]:
                if n not in visited:
                    visited.add(n)
                    q.append(n)
        # source에서 시작하는 loop에 destination이 없다면, path가 없음: False
        return False