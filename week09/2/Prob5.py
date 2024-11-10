# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        # use DFS-inorder method
        lst = []
        def DFS(node):
            if not node:
                return
            DFS(node.left)
            lst.append(node.val)
            DFS(node.right)
        
        DFS(root)
        return lst[k-1]
