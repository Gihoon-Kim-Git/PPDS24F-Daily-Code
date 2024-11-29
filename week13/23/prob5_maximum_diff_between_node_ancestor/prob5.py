class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def maxAncestorDiff(root):
    def helper(node, current_min, current_max):
        if not node:
            return current_max - current_min
        
        current_min = min(current_min, node.val)
        current_max = max(current_max, node.val)
        
        left_diff = helper(node.left, current_min, current_max)
        right_diff = helper(node.right, current_min, current_max)
        
        return max(left_diff, right_diff)
    
    return helper(root, root.val, root.val)

# Example usage
root = TreeNode(8)
root.left = TreeNode(3)
root.right = TreeNode(10)
root.left.left = TreeNode(1)
root.left.right = TreeNode(6, TreeNode(4), TreeNode(7))
root.right.right = TreeNode(14, TreeNode(13))

print(maxAncestorDiff(root))  # Output: 7
