# undirected 그래프의 edge list가 주어졌을때 source에서 destination까지의 경로 존재 여부 찾기
# BFT로 하면 stress test 통과 못함

class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        if source == destination:
            return True
        if [source, destination] in edges:
            return True

        neighbor = [[] for _ in range(n)]
        visit = [False] * n

        for a, b in edges:
            neighbor[a].append(b)
            neighbor[b].append(a)
        
        def help(node):
            if visit[node]:
                return
            else:
                visit[node] = True
                for child in neighbor[node]:
                    help(child)
        help(source)

        return visit[destination]
        

"""
class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        if source == destination:
            return True
        if [source, destination] in edges:
            return True
        neighbor = [[] for _ in range(n)]
        visit = [False] * n
        # queue = [source]
        queue = deque([source])
        for a, b in edges:
            neighbor[a].append(b)
            neighbor[b].append(a)
        
        def helper(n):
            if visit[n]:
                return
            else:
                visit[n] = True
        
        while queue:
            parent = queue.popleft()
            for child in neighbor[parent]:
                if child == destination:
                    return True
                if not visit[child] and not child in queue:
                    queue.append(child)
            helper(parent)
        
        return False
"""