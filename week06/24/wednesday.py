# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        # Helper function to check if a node is a leaf
        def isLeaf(node):
            return node is not None and node.left is None and node.right is None
        
        # Base case: if the root is None, there are no leaves
        if root is None:
            return 0
        
        left_sum = 0
        # Check if the left child is a leaf
        if root.left and isLeaf(root.left):
            left_sum += root.left.val
        # Recursively find left leaves in the left and right subtrees
        left_sum += self.sumOfLeftLeaves(root.left)
        left_sum += self.sumOfLeftLeaves(root.right)
        
        return left_sum