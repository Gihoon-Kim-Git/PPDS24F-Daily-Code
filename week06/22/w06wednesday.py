class Solution(object):
    def sumOfLeftLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def is_leaf(node):
            return node is not None and node.left is None and node.right is None
        
        if root is None:
            return 0
        
        total = 0
        
        if root.left and is_leaf(root.left):
            total += root.left.val
        
        total += self.sumOfLeftLeaves(root.left)
        total += self.sumOfLeftLeaves(root.right)
        
        return total
