from collections import Optional 
import math

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        INF = math.inf
        def dfs(node, mn, mx):
            ans = 0
            ans = max(ans, node.val-mn)
            ans = max(ans, mx-node.val)
            if node.left:
                ans = max(ans, dfs(node.left, min(mn, node.val), max(mx, node.val)))
            if node.right:
                ans = max(ans, dfs(node.right, min(mn, node.val), max(mx, node.val)))
            return ans
        return dfs(root, INF, -INF)     