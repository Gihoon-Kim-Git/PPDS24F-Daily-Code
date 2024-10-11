# # Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution(object):
    def sumOfLeftLeaves(self, root):
        ans = 0
        temp = root

        if temp == None or temp.left == None and temp.right == None:
            return 0        
        
        if temp.left and temp.left.left is None and root.left.right is None:
            ans += root.left.val

        ans += self.sumOfLeftLeaves(temp.left)
        ans += self.sumOfLeftLeaves(temp.right)

        return ans

# a = TreeNode(1)
# a.right = TreeNode(2)

# solution = Solution()
# result = solution.sumOfLeftLeaves(a)
# print(result)