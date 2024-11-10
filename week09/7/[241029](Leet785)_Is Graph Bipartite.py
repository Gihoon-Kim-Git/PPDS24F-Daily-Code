"""문제
here is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:
    There are no self-edges (graph[u] does not contain u).
    There are no parallel edges (graph[u] does not contain duplicate values).
    If v is in graph[u], then u is in graph[v] (the graph is undirected).
    The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.

A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

Return true if and only if it is bipartite.
"""
"""Constraints
    graph.length == n
    1 <= n <= 100
    0 <= graph[u].length < n
    0 <= graph[u][i] <= n - 1
    graph[u] does not contain u.
    All the values of graph[u] are unique.
    If graph[u] contains v, then graph[v] contains u."""
    

"""문제풀이
    1. 현재 graph는 adj_list라고 보면 된다. 각 index가 노드 번호임.
    2. dfs를 진행하는데, 나와 나의 이웃을 다른 색깔로 visited 표시하도록 한다. visited를 true,false가 아니라 0,1,-1로 표시. 0(미방문), 1(방문 색깔1), -1(방문 색깔2)
    3. 모든 노드로 각각 DFS를 수행하는데, 현재 노드에서 연결된 노드 중 이미 방문한 노드가 나와 같은 visited 값을 가지고 있으면 이분그래프가 아니다. 이분그래프가 아니면 이후 노드는 탐색하지 않음.
        ※이때, 모든 노드로 DFS를 수행하는 이유 : 그래프의 모든 노드가 이어져 있지 않고, 여러 개의 부분 그래프로 이뤄진 케이스가 존재할 수 있음.
"""
"""내가 풀때 잘 안 풀렸던 이유. : 처음에 visited 값을 0, 1, 2로 구분해서 반대값으로 설정하는 코드를 복잡하게 짰다. 근데 GPT 물어보니까 이것도 간단하게 해결 가능하네...
    # 반대 색상 할당 (1 -> 2 또는 2 -> 1)
    if not self.dfs_util(graph, neigh, visited, 3 - color):
        return False
"""

#%%
#방법1
def dfs_util(graph, v, visited):
    for neigh in graph[v]:
        if visited[neigh] == 0:
            #바로 직전에 있는 노드와 다른 숫자로 분류
            visited[neigh] = -visited[v] #현재노드와 반대색상 할당
            if dfs_util(graph, neigh, visited) == False : #현재위치에서 또 dfs 수행.
                return False
        elif visited[v] == visited[neigh] :
            return False
    return True
            

def isBipartite(graph):
    visited = [0 for _ in range(len(graph))]
    
    for i in range(len(graph)):
        if visited[i] == 0:
            visited[i] = 1 #첫방문 시 1로 시작
            if dfs_util(graph, i, visited) == False :
                return False
    return True

graph1 = [[1,3],[0,2],[1,3],[0,2]]
print(isBipartite(graph1))

graph2 = [[1,2,3],[0,2],[0,1,3],[0,2]]
print(isBipartite(graph2))

graph3 = [[3,4,6],[3,6],[3,6],[0,1,2,5],[0,7,8],[3],[0,1,2,7],[4,6],[4],[]]
isBipartite(graph3)

# %%
#방법2 : visited와 color를 따로 관리하는 방법. 
        #(color를 argument로 넘겼다.)

def dfs_util(graph, v, visited, color):
    visited[v] = color
    for neigh in graph[v]:
        if visited[neigh] == 0:
            if not dfs_util(graph, neigh, visited, -color): #반대 색상 할당
                return False
        elif visited[neigh] == visited[v]: # 나와 내 이웃이 같은 색깔일때
            return False
    return True

def isBipartite(graph):
    visited = [0 for _ in range(len(graph))]
    
    for i in range(len(graph)):
        if visited[i] == 0:
            if dfs_util(graph, i, visited, 1) == False:
                return False
    return True
# %%

# 방법3 : visited 값을 0,1,2로
class Solution(object):
    def dfs_util(self, graph, v, visited, color):
        # 현재 노드에 색상 할당 (색상 1 또는 2)
        visited[v] = color
        # 모든 인접 노드에 대해 검사
        for neigh in graph[v]:
            if visited[neigh] == 0:  # 아직 방문하지 않은 경우
                # 반대 색상 할당 (1 -> 2 또는 2 -> 1)
                if not self.dfs_util(graph, neigh, visited, 3 - color):
                    return False
            elif visited[neigh] == visited[v]:  # 같은 색상이 이미 존재하는 경우
                return False
        return True

    def isBipartite(self, graph):
        visited = [0] * len(graph)  # 방문 상태 및 색상 정보 초기화
        for i in range(len(graph)):
            if visited[i] == 0:  # 아직 방문하지 않은 노드가 있다면
                if not self.dfs_util(graph, i, visited, 1):  # 색상 1로 시작하여 DFS
                    return False
        return True