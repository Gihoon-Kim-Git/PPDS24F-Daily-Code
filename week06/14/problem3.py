## Wednesday. [Sum of Left Leaves](https://leetcode.com/problems/sum-of-left-leaves/description/)


# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        ans = 0
        if not root:
            return 0
        
        if root.left:
            if not root.left.left and not root.left.right:
                ans += root.left.val

            else:
                ans += self.sumOfLeftLeaves(root.left)
        
        ans += self.sumOfLeftLeaves(root.right)

        return ans