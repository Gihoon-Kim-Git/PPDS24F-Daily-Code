# Given the root of a binary tree, return its maximum depth.
# A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def maxDepth(root):
    # Base Case: tree is empty
    if root == None:
        return 0 # depth is 0

    # Recursively find the maximum depth of the left subtree
    leftDepth = maxDepth(root.left)

    # Recursively find the maximum depth of the right subtree
    rightDepth = maxDepth(root.right)

    # Maximum depth of the current node
    # : greater depth between the two subtrees + 1
    return max(leftDepth, rightDepth) + 1

# Test cases for maxDepth function
if __name__ == "__main__":
    # Helper function to create a new TreeNode
    def newNode(val):
        return TreeNode(val)

    # Example 1: Create the binary tree [3,9,20,null,null,15,7]
    root = newNode(3)
    root.left = newNode(9)
    root.right = newNode(20)
    root.right.left = newNode(15)
    root.right.right = newNode(7)

    # Test maxDepth function
    print("Maximum Depth of the Tree (Example 1):", maxDepth(root))  # Output: 3

    # Example 2: Create the binary tree [1,null,2]
    root2 = newNode(1)
    root2.right = newNode(2)

    # Test maxDepth function
    print("Maximum Depth of the Tree (Example 2):", maxDepth(root2))  # Output: 2

    # Example 3: Create an empty tree
    root3 = None
    print("Maximum Depth of the Tree (Example 3):", maxDepth(root3))  # Output: 0

    # Example 4: Create a tree with only one node [1]
    root4 = newNode(1)
    print("Maximum Depth of the Tree (Example 4):", maxDepth(root4))  # Output: 1

    # Example 5: Create a more complex tree [5,3,8,1,4,null,9]
    root5 = newNode(5)
    root5.left = newNode(3)
    root5.right = newNode(8)
    root5.left.left = newNode(1)
    root5.left.right = newNode(4)
    root5.right.right = newNode(9)
    print("Maximum Depth of the Tree (Example 5):", maxDepth(root5))  # Output: 3