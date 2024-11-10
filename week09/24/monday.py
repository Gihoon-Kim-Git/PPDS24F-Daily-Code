from typing import List

class UnionFind:
    def __init__(self):
        self.id = {}
    def find(self, x):
        y = self.id.get(x, x)
        if y != x:
            self.id[x] = y = self.find(y)
        return y
    def union(self, x, y):
        self.id[self.find(x)] = self.find(y)

class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        uf = UnionFind()
        for edge in edges:
            uf.union(edge[0], edge[1])
        return uf.find(source) == uf.find(destination)
