# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        def dfs(node, current_max, current_min):
            if not node:
                # Return the difference between the maximum and minimum ancestor values
                return current_max - current_min
            
            # Update the current maximum and minimum values
            current_max = max(current_max, node.val)
            current_min = min(current_min, node.val)
            
            # Recur for left and right children
            left_diff = dfs(node.left, current_max, current_min)
            right_diff = dfs(node.right, current_max, current_min)
            
            # Return the maximum difference found in either subtree
            return max(left_diff, right_diff)
        
        # Initial call to DFS with the root value as both the current max and min
        return dfs(root, root.val, root.val)