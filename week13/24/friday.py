# Maximum Difference Between Node and Ancestor
from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        # Recursive DFS
        def dfs(root, min_val, max_val, res):
            if not root:
                return
            res[0]=max(res[0],abs(min_val-root.val),abs(max_val-root.val))
            min_val = min(root.val, min_val)
            max_val = max(root.val, max_val)
            dfs(root.left, min_val, max_val, res)
            dfs(root.right, min_val, max_val, res)
        res=[0]
        dfs(root, root.val, root.val, res)
        return res[0]