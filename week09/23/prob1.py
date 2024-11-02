## Find if Path Exists in Graph

def validPath(n, edges, source, destination):
    # initialize graph
    graph = [[] for _ in range(n)]
    for edge in edges:
        graph[edge[0]].append(edge[1])
        graph[edge[1]].append(edge[0])
    
    # Recursive DFS
    def dfs(graph, source, destination, visited):
        if source == destination:
            return True
        visited[source] = 1 # mark the current node as visited
        for neighbor in graph[source]:
            if visited[neighbor] == 0:
                if dfs(graph, neighbor, destination, visited):
                    return True
        return False
    # Initialize a list to keep track of visited vertices
    visited = [0] * n
    return dfs(graph, source, destination, visited)

# Driver Code
if __name__=="__main__":
    # input
    edges = [[0,1],[0,2],[3,5],[5,4],[4,3]]
    n = 6
    # Execution
    print(validPath(n, edges, 0, 5))