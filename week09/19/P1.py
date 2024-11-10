class Solution1(object):
    def validPath(self, n, edges, source, destination):
        visited = [False] * n
        
        def dfs_util(v):
            visited[v] = True
            for index in edges:
                if index[0] == v and not visited[index[1]]:
                    dfs_util(index[1])
                if index[1] == v and not visited[index[1]]:
                    dfs_util(index[0])

        dfs_util(source)
        return visited[destination]

class Solution2(object):
    def validPath(self, n, edges, source, destination):
        visited = [False] * n
        
        adj = {}
        for k in range(n):
            adj[k] = []
        for i in edges:
            adj[i[0]].append(i[1])
            adj[i[1]].append(i[0])

        def dfs_util(v):
            visited[v] = True
            for neighbor in adj[v]:
                if not visited[neighbor]:
                    dfs_util(neighbor)

        dfs_util(source)
        return visited[destination]

if __name__ == "__main__":
    n = 3
    edges = [[0,1], [1,2], [2,0]]
    source = 0
    destination = 2
    result = Solution1()
    print(result.validPath(n, edges, source, destination))
    n = 6
    edges = [[0,1], [0,2], [3,5], [5,4], [4,3]]
    source = 0
    destination = 5
    result = Solution2()
    print(result.validPath(n, edges, source, destination))