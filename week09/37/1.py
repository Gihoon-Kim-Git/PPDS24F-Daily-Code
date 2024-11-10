class Solution:
    def helper(self, edges, visit, source):
        for edge in edges:
            if source in edge:
                for e in edge:
                    if e != source:
                        if visit[e]==False:
                            visit[e]=True
                            self.helper(edges, visit, e)
                        
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        visit=dict()
        for i in range(n):
            visit[i+1]=False
        
        visit[source]=True
        self.helper(edges, visit, source)
        if visit[destination]:
            return True
        
        return False

        