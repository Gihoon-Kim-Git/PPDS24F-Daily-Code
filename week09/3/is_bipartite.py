# Problem Summary:
# We are given an undirected graph with `n` nodes, numbered from 0 to n - 1.
# The graph is represented as a 2D list `graph`, where `graph[u]` is a list of nodes
# that node `u` is connected to by an undirected edge. The graph has the following properties:
# - No self-edges: `graph[u]` does not contain `u`.
# - No parallel edges: `graph[u]` does not contain duplicate values.
# - The graph is undirected: If `v` is in `graph[u]`, then `u` is in `graph[v]`.
# - The graph may not be connected: There may be nodes `u` and `v` with no path between them.

# Goal:
# Determine if the graph is bipartite.
# A graph is bipartite if we can partition the nodes into two sets
# such that every edge connects a node in one set to a node in the other.

"""
ref. https://www.geeksforgeeks.org/bipartite-graph/
Checking if a graph is bipartite is like trying to color the graph using only two colors,
so that no two adjacent vertices have the same color.
One approach is to check whether the graph is 2-colorable or not using backtracking algorithm m coloring problem.
A common and efficient way to solve this is by using Breadth-First Search (BFS).
The idea is to traverse the graph level by level and assign colors alternately to the vertices as we proceed.
"""

def isBipartite(graph):
    # initialization: list to keep track of the colors assigned to each node
    n = len(graph)
    colors = [-1] * n # -1: uncolored node

    # helper function: perform Breadth-First Search (BFS)
    def bfs(start):
        # initialization
        queue = [start] # queue for BFS
        colors[start] = 0 # color the starting node with 0

        # BFS
        while queue:
            node = queue.pop(0)  # dequeue the current node

            # iteration over all the neighbors of the current node
            for neighbor in graph[node]:
                # uncolored neighbor
                if colors[neighbor] == -1:
                    # color it with the opposite color (0 -> 1, 1 -> 0)
                    colors[neighbor] = 1 - colors[node]
                    queue.append(neighbor)  # enqueue neighbor for further processing
                # neighbor has same color with current node
                elif colors[neighbor] == colors[node]:
                    # graph is not bipartite
                    return False

        # BFS completes without conflicts, graph is bipartite so far
        return True
    
    # check each component of the graph
    for i in range(n):
        if colors[i] == -1: # uncolored node: new component
            if not bfs(i): # check if component is bipartite
                return False
    
    # all components are bitartite: whole graph is bipartite
    return True

# Example usage
if __name__ == "__main__":
    # Example 1: Should return False
    graph1 = [[1, 2, 3], [0, 2], [0, 1, 3], [0, 2]]
    print(isBipartite(graph1))  # Output: False

    # Example 2: Should return True
    graph2 = [[1, 3], [0, 2], [1, 3], [0, 2]]
    print(isBipartite(graph2))  # Output: True

"""
0806a@LAPTOP-SAGEKIM MINGW64 ~/Desktop/Lecture/SNUGSDS/ProgrammingPractice/PPDS24F-Daily-Code/week09 (main)
$ python is_bipartite.py
False
True
"""