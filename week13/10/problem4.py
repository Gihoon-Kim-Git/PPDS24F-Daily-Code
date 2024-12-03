from collections import Optional 

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
   
class Solution:
    
    def maxDepth(self, root: Optional[TreeNode]) -> int:

        def dfs(root, curr_depth):
            if not root:
                return curr_depth
            return max(dfs(root.left, curr_depth+1), dfs(root.right, curr_depth+1))
        return dfs(root,0)