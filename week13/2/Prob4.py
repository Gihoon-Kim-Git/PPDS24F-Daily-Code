from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        
        max_depth = 0
        max_depth = max(max_depth, self.maxDepth(root.left))
        max_depth = max(max_depth, self.maxDepth(root.right))

        return max_depth + 1