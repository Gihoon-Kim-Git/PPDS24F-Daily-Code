# source -> destination까지 path가 존재하는지
# bfs: 그래프 연결성 검사하기

def validPath(n, edges, source, destination):

    if source == destination:
        return True

    graph = {}
    for w, v in edges:
        if w not in graph:
            graph[w] = []
        if v not in graph:
            graph[v] = []
        graph[w].append(v)
        graph[v].append(w)
    
    # print(graph)
    visited = set([source])
    queue = [source]

    while queue:
        current = queue.pop(0)
        for neighbor in graph[current]:
            if neighbor == destination:
                return True
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor)


    return False



n = 3
edges = [[0,1],[1,2],[2,0]]
source = 0
destination = 2
            
# n = 6
# edges = [[0,1],[0,2],[3,5],[5,4],[4,3]]
# source = 0
# destination = 5
            
# n = 10
# edges = [[0,7],[0,8],[6,1],[2,0],[0,4],[5,8],[4,7],[1,3],[3,5],[6,5]]
# source = 7
# destination = 5

print(validPath(n, edges, source, destination))