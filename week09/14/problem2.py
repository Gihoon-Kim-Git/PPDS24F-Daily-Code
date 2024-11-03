# week 09

## Tuesday. [Is Graph Bipartite?](https://leetcode.com/problems/is-graph-bipartite/description/?envType=problem-list-v2&envId=graph)

class BipartiteChecker:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        #Dictionary
        color = {}
        for each_node in range(len(graph)):
           #if not visited already
            if each_node not in color:
                neighbors = [each_node]
                next_neighbors = []
                curr_color = True
                while neighbors:
                    out = neighbors.pop(0)
                    if out in color:
                        #Check if current color is intended color
                        if color[out] != curr_color:
                            return False
                    else:
                        color[out] = curr_color
                        for i in graph[out]:
                            next_neighbors.append(i)
                    if neighbors == []:
                        curr_color = not curr_color
                        neighbors, next_neighbors = next_neighbors,neighbors
        return True