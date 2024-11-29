# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        def dfs(node, cur_min, cur_max):
            if not node:
                return cur_max - cur_min
            cur_min = min(cur_min, node.val)
            cur_max = max(cur_max, node.val)
            left = dfs(node.left, cur_min, cur_max)
            right = dfs(node.right, cur_min, cur_max)
            return max(left, right)
        
        return dfs(root, root.val, root.val)