# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:        
        def dfs(node, small, big):
            if not node:
                return big - small
            small = min(node.val, small)
            big = max(node.val, big)
            left = dfs(node.left, small, big)
            right = dfs(node.right, small, big)
            return max(left, right)
        return dfs(root, root.val, root.val)