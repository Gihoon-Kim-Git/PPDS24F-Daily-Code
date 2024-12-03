# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        depth=1
        def dfs(root,depth):
            if(root==None):
                return depth
            depth+=1

            depth = max(dfs(root.left,depth),dfs(root.right,depth))
            return depth
        depth =dfs(root,depth)

        return depth-1
        