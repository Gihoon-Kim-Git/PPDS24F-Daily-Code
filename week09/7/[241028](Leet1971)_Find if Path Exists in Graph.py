"""문제
There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

You want to determine if there is a valid path that exists from vertex source to vertex destination.

Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise.
"""
"""Constraint
    1 <= n <= 2 * 105
    0 <= edges.length <= 2 * 105
    edges[i].length == 2
    0 <= ui, vi <= n - 1
    ui != vi
    0 <= source, destination <= n - 1
    There are no duplicate edges.
    There are no self edges.
"""

"""문제풀이
    1. DFS를 활용해보자. DFS에서 outer for loop은 제외.
    2. 일단 edges array를 돌면서 각 vertex별로 adjacent list를 정리한 list / dict 형성
    3-1. 시작점을 source로 해서 dfs 돌린 후에, visited[destination] == true이면 return true else false?
    3-2. DFS를 도는데, 시작점을 source로 하고, DFS_util 중에서 neigh==destination이면 return true. else false;
"""

#방법1
def validPath(n, edges, source, destination):
    #edges array 바탕으로 adjacent list 정리
    adj_list = [[] for _ in range(n)]
    
    for e in edges:
        adj_list[e[0]].append(e[1])
        adj_list[e[1]].append(e[0])
        
    #dfs를 위한 정리
    visited= [False]*n

    #dfs_util
    def dfs_util(adj_list, visited, v):
        visited[v] = True;
        
        for neigh in adj_list[v]:
            if visited[neigh] == False:
                dfs_util(adj_list, visited, neigh)
            # else :
            #     return

    dfs_util(adj_list, visited, source)
    
    return True if visited[destination]==True  else False    

#방법 2
def validPath(n, edges, source, destination):
    #edges array 바탕으로 adjacent list 정리
    adj_list = [[] for _ in range(n)]
    
    for e in edges:
        adj_list[e[0]].append(e[1])
        adj_list[e[1]].append(e[0])
        
    #dfs를 위한 정리
    visited= [False]*n

    #dfs_util
    def dfs_util(v, destination):
        if v == destination :
            return True
        visited[v] = True;
        for neigh in adj_list[v]:
            if visited[neigh] == False:
                if dfs_util(neigh, destination): # 이부분 유의!!! 
                    return True
        return False
    
    return  dfs_util(source, destination)


n = 3
edges = [[0,1],[1,2],[2,0]]
source = 0
destination = 2
print(validPath(n, edges, source, destination)) # true

n = 6
edges = [[0,1],[0,2],[3,5],[5,4],[4,3]]
source = 0
destination = 5
validPath(n, edges, source, destination) # false
# %%
