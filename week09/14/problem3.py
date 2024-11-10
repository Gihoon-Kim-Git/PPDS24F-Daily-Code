# week 09

## Wednesday. [Maximum Depth of N-ary Tree](https://leetcode.com/problems/maximum-depth-of-n-ary-tree/description/?envType=problem-list-v2&envId=tree)

class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
class MaxDepthFinder:
    def maxDepth(self, root: 'Node') -> int:
        if root == None:
            return 0
        else:
            depth = 0
            nodes_queue = [root]
            next_nodes_queue = []
            while(nodes_queue):
                node_out = nodes_queue.pop(0)
                for child in node_out.children:
                    next_nodes_queue.append(child)
                if nodes_queue == []:
                    nodes_queue, next_nodes_queue = next_nodes_queue, nodes_queue
                    depth += 1
            return depth