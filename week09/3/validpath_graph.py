# Problem Summary:
# We are given a bi-directional graph with `n` vertices labeled from 0 to n - 1.
# The graph's edges are given as a 2D integer array `edges`,
# where each edge connects two vertices `u_i` and `v_i`. edges[i] = [u_i, v_i]
# The goal is to determine if there is a valid path from vertex `source` to vertex `destination`.

from collections import deque

def validPath(n, edges, source, destination):

    if source == destination:
        return True
    
    ##### Breadth-First Search (BFS) #####

    # build adjacency list to represent graph
    graph = {}
    # initialization: empty list for each vertex
    for i in range(n):
        graph[i] = []
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)

    # perform BFS to check for valid path
    visited = set() # keep track of visited notes
    # initialization of queue with source vertex
    queue = deque([source])

    while queue:
        curr = queue.popleft()  # get current node from the queue
        
        if curr == destination: # reached destination
            return True
        
        visited.add(curr) # mark the current node as visited

        # iterate over all the neighbors of the current node
        for neighbor in graph[curr]:
            if neighbor not in visited:
                queue.append(neighbor) # add unvisited neighbors to queue

    # all possible paths exhauted and did not reach the destination
    return False

# Example usage
# Test cases using if __name__ == "__main__"
if __name__ == "__main__":
    # Example 1: Should return True
    n1 = 3
    edges1 = [[0, 1], [1, 2], [2, 0]]
    source1 = 0
    destination1 = 2
    print(validPath(n1, edges1, source1, destination1))  # Output: True

    # Example 2: Should return False
    n2 = 6
    edges2 = [[0, 1], [0, 2], [3, 5], [5, 4], [4, 3]]
    source2 = 0
    destination2 = 5
    print(validPath(n2, edges2, source2, destination2))  # Output: False

    # Additional Test Case 1: Should return True
    n3 = 5
    edges3 = [[0, 1], [1, 2], [2, 3], [3, 4]]
    source3 = 0
    destination3 = 4
    print(validPath(n3, edges3, source3, destination3))  # Output: True

    # Additional Test Case 2: Should return True
    n4 = 7
    edges4 = [[0, 6], [6, 5], [5, 4], [4, 3], [3, 2], [2, 1], [1, 0]]
    source4 = 0
    destination4 = 3
    print(validPath(n4, edges4, source4, destination4))  # Output: True

"""
0806a@LAPTOP-SAGEKIM MINGW64 ~/Desktop/Lecture/SNUGSDS/ProgrammingPractice/PPDS24F-Daily-Code/week09 (main)
$ python validpath_graph.py
True
False
True
True
"""