# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution(object):
    def inorder_traversal(self, root):
        # Initialize an empty list to store the values
        result = []
        
        # Helper function to perform recursive inorder traversal
        def helper(node):
            if node:
                helper(node.left)  # Traverse left subtree
                result.append(node.val)  # Store the current node's value
                helper(node.right)  # Traverse right subtree
        
        # Call the helper function with the root node
        helper(root)
        return result

    def kthSmallest(self, root, k):
        """
        :type root: Optional[TreeNode]
        :type k: int
        :rtype: int
        """
        # Get the inorder traversal result, which will be sorted
        res = self.inorder_traversal(root)
        # Return the k-th smallest element (adjust for 0-based index)
        return res[k - 1]
