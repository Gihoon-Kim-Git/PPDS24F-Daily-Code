# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        array = []

        def dfs(root):
            if not root:
                return
            if root.left:
                dfs(root.left)

            array.append(root.val)

            if root.right:
                dfs(root.right)

        dfs(root)
        return array[k-1]