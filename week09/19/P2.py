class Solution(object):
    def isBipartite(self, graph):
        visited = [0] * len(graph)
        
        def dfs_util(v, color):
            bipartite = True
            visited[v] = color
            for neighbor in graph[v]:
                if visited[neighbor] == color:
                    return False
                elif visited[neighbor] == 0:
                    bipartite = dfs_util(neighbor, -color)
            return bipartite

        for i in range(len(graph)):
            if (visited[i] == 0 and not dfs_util(i, 1)):
                return False
        return True

if __name__ == "__main__":
    graph = [[1,3],[0,2],[1,3],[0,2]]
    result = Solution()
    print(result.isBipartite(graph))
    graph = [[],[2,4,6],[1,4,8,9],[7,8],[1,2,8,9],[6,9],[1,5,7,8,9],[3,6,9],[2,3,4,6,9],[2,4,5,6,7,8]]
    print(result.isBipartite(graph))