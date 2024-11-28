from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        def max_find(root: Optional[TreeNode], cur_max: int, cur_min: int) -> int:
            if not root:
                return cur_max - cur_min
            
            # find max, min value
            cur_max = max(cur_max, root.val)
            cur_min = min(cur_min, root.val)
            
            # Recursive for left and right subtrees
            left_diff = max_find(root.left, cur_max, cur_min)
            right_diff = max_find(root.right, cur_max, cur_min)
            
            # Return the maximum difference found
            return max(left_diff, right_diff)

        return max_find(root, root.val, root.val)