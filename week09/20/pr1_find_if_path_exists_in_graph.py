class Solution:
    def validPath(self, n: int, edges: list[list[int]], source: int, destination: int) -> bool:
        # make adjacent list
        g = {i:[] for i in range(n)} #dictionary
        for u,v in edges:
            g[u] += [v]
            g[v] += [u]
        
        visited = set()

        # Recursive
        def helper(node):
            if node == destination: return True # 아..함수 안에 사용하면 바깥 함수 varialbe 사용가능하네
            visited.add(node)
            print(visited)
            for neighbor in g[node]:
                if neighbor not in visited:
                    if helper(neighbor):
                        return True
            return False
        return helper(source)

s = Solution()
n = 6
edges = [[0,1],[0,2],[3,5],[5,4],[4,3]]
print(s.validPath(n,edges,0,5))