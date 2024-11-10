# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.ans=0
    def dfs(self,root):
        if root== None:
            return
        if(root.left and root.left.left is None and root.left.right is None):
            self.ans+= root.left.val
        self.dfs(root.left)
        self.dfs(root.right)
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        self.dfs(root)
        return self.ans