# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from collections import deque

# DFS
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        ls = []
        self.inorder(root, ls)
        return ls[k-1]
    
    def inorder(self, root, ls):
        if root is None:
            return
        self.inorder(root.left, ls)
        ls.append(root.val) 
        self.inorder(root.right, ls)
        
# BFS
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        nodes = deque()
        val = []
        nodes.append(root)
        while nodes:
            node = nodes.popleft()
            if node:
                val.append(node.val)
                for child in [node.left, node.right]:
                    nodes.append(child)
        val.sort()
        return val[k-1] 