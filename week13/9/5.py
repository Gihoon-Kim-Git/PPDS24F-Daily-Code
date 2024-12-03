class Solution:
    def helper(self, node, max_val, min_val):
        if not node:
            return max_val - min_val
        
        # Update max and min values
        max_val = max(max_val, node.val)
        min_val = min(min_val, node.val)
        
        # Recurse for left and right subtrees
        left_diff = self.helper(node.left, max_val, min_val)
        right_diff = self.helper(node.right, max_val, min_val)
        
        # Return the maximum difference found
        return max(left_diff, right_diff)
    
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        return self.helper(root, root.val, root.val)