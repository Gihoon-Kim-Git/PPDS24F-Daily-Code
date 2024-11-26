# week 13

# Thursday. [Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/description//)

class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        def depth(root, dep):
            lh, rh = -1, -1  # Initialize the depths of left and right subtrees
            if root and root.left:
                lh = depth(root.left, dep + 1)  # Recursively calculate the left subtree depth
            if root and root.right:
                rh = depth(root.right, dep + 1)  # Recursively calculate the right subtree depth
            return max(lh, rh, dep)  # Return the max of left, right, and current depth
        
        return depth(root, 1) if root else 0  # If root is None, return 0; else start recursion