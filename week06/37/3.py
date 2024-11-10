class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        return dfs(root)
        
    def dfs(node):
        if not node:
            return 0
        left_sum = dfs(node.left)
        right_sum = dfs(node.right)

        if node.left and not node.left.left and not node.left.right:
            left_sum += node.left.val

        return left_sum + right_sum