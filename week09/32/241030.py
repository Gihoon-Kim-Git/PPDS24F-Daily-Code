"""
# Definition for a Node.
class Node:
    def __init__(self, val: Optional[int] = None, children: Optional[List['Node']] = None):
        self.val = val
        self.children = children
"""

class Solution:
    
    def maxDepth(self, root: 'Node') -> int:
        if not root:
            return 0
            
        def dfs(node):
            max_depth = 0
            
            if not node:
                return 0
            for child in node.children:
                max_depth = max(max_depth, dfs(child)+1)
            return max_depth
        return dfs(root)+1