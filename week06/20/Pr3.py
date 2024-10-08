# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def sumOfLeftLeaves(self, root: TreeNode) -> int:
        ans = [0]
        if not root or not (root.left or root.right) : return ans[0]

        def DFS(node):
            if node.left:
                if not node.left.left and not node.left.right:
                    ans[0] += node.left.val
                DFS(node.left)
            if node.right:
                DFS(node.right)
        DFS(root)
        return ans[0]
        
            