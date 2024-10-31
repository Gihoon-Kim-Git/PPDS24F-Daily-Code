# A graph is bipartite if the nodes can be partitioned into two independent sets A and B 
# such that every edge in the graph connects a node in set A and a node in set B.
# dfs 사용

def isBipartite(graph):

    color = [None] * len(graph)

    def dfs(current, c):
        color[current] = c
        for neighbor in graph[current]:
            if color[neighbor] == color[current]: 
                return False   # 인접 노드가 같은 색이면 bipartite 아님
            
            if color[neighbor] is None and not dfs(neighbor, "black" if c=="white" else "white"):  # 위에서 전달한 False 감지하는 경우 즉시 종료
                return False
            
        return True
        
    for i in range(len(graph)):
        if color[i] is None:
            if not dfs(i, "black"):  
                return False          
    return True

    

    

#graph = [[1],[0,3],[3],[1,2]]    # true
graph = [[1,3],[0,2],[1,3],[0,2]]   # true
#graph = [[1,2,3],[0,2],[0,1,3],[0,2]]   # false

print(isBipartite(graph))

