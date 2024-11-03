# graph가 두개의 독립된 set으로 나뉘어질 수 있는가
# 단, 인접한 노드는 서로 다른 set에 있어야 함

class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        groupDic = {}
        visited = [False] * len(graph)

        def helper(n, group):
            visited[n] = True
            groupDic[n] = group
            for node in graph[n]:
                if visited[node]:
                    if groupDic[node] != 1-group:
                        return False
                else:
                    if not helper(node, 1-group):
                        return False
            return True

        for i in range(len(graph)):
            if not visited[i]:
                if not helper(i, 0):
                    return False

        return True

"""
# BFT -> 속도 더 빠름
class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        visited = [-1] * len(graph)
        for i in range(len(graph)):
            if visited[i] == -1:
                q = deque([i])
                visited[i] = 0
                while q:
                    node = q.popleft()
                    for adj in graph[node]:
                        if visited[adj] == -1:
                            visited[adj] = 1-visited[node]
                            q.append(adj)
                        elif visited[adj] != 1-visited[node]:
                            return False
        return True
                            
"""