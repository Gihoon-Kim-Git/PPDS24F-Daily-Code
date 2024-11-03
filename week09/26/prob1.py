class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        adj = collections.defaultdict(list)
        for s, d in edges:
            adj[s] += [d]
            adj[d] += [s]



        if len(adj) == 0:
            return True

        to_visit = []
        visited = []
        to_visit += adj[source]
        to_visit = deque(to_visit)
        visited = set(visited)

        while to_visit:
            curr = to_visit.pop()
            if curr == destination:
                return True
            for neighbor in adj[curr]:
                if neighbor not in visited:
                    visited.add(neighbor)
                    to_visit += [neighbor]
                
        return False

