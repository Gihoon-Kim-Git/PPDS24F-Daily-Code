class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def sumOfLeftLeaves(root):
    total = 0
    def dfs(node, left):
        nonlocal total
        if not node:
            return
        dfs(node.left, True)
        dfs(node.right, False)

        if not node.left and not node.right and left:
            total += node.val
    dfs(root, False)
    return total

# Driver code to test the function
if __name__ == "__main__":
    # Create a binary tree
    #       3
    #      / \
    #     9   20
    #        /  \
    #       15   7
    root = TreeNode(3)
    root.left = TreeNode(9)
    root.right = TreeNode(20)
    root.right.left = TreeNode(15)
    root.right.right = TreeNode(7)

    # Test the sumOfLeftLeaves function
    result = sumOfLeftLeaves(root)
    print("Sum of left leaves:", result)  # Output should be 24 (9 + 15)
