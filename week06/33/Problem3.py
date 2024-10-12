# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        ans = 0
        left = root.left
        right = root.right
        if left:
            if not left.left and not left.right:
                ans += left.val
            else:
                ans += self.sumOfLeftLeaves(left)
        if right:
                ans += self.sumOfLeftLeaves(right)    
        return ans

        