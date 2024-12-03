# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:        
        def helper(root, depth):
            if not root:
                return depth
            else:
                return max(helper(root.left, depth+1), helper(root.right, depth+1))
        
        return helper(root, 0)