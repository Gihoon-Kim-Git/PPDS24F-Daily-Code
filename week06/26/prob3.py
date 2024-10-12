# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        stack = [(root, False)]
        curr = None
        result = 0

        while stack:
            curr, is_left = stack.pop()
            if curr.left:
                stack.append((curr.left, True))
            elif curr.right is None and is_left:
                result += curr.val
            if curr.right:
                stack.append((curr.right, False))
                
                    
        
        return result

        
            
        