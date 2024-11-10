# Given the root of a binary search tree (BST) and an integer k, 
# the goal is to find the kth smallest value in the BST. 
# The BST properties are:
# - The left subtree of a node contains only nodes with values less than the node's value.
# - The right subtree of a node contains only nodes with values greater than the node's value.
# - Both the left and right subtrees must also be binary search trees.
#
# Approach: Perform an in-order traversal of the tree to get values in ascending order.
# The kth element in this order is the answer since an in-order traversal of a BST yields elements in sorted order.
# https://youtu.be/WLvU5EQVZqY?si=YQ0dMItm-0nnWWpo
#
# Constraints:
# - The number of nodes in the tree is n, with 1 <= k <= n <= 10^4.
# - Node values are within the range [0, 10^4].

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def kthSmallest(root, k):

    # helper function for in-order traversal
    def in_order_traversal(node):
        # node is None: return an empty list (base case for recursion)
        if not node:
            return []
        # recursive traversal: left subtree -> current node -> right subtree
        return in_order_traversal(node.left) + [node.val] + in_order_traversal(node.right)
    
    # perform in-order traversal in BST: list of sorted values
    sorted_BST_nodes = in_order_traversal(root)

    return sorted_BST_nodes[k-1]


# Example test code
# Construct the example trees:
# Example 1: [3, 1, 4, None, 2]
root1 = TreeNode(3)
root1.left = TreeNode(1)
root1.right = TreeNode(4)
root1.left.right = TreeNode(2)

# Example 2: [5, 3, 6, 2, 4, None, None, 1]
root2 = TreeNode(5)
root2.left = TreeNode(3)
root2.right = TreeNode(6)
root2.left.left = TreeNode(2)
root2.left.right = TreeNode(4)
root2.left.left.left = TreeNode(1)

# Test cases
print(kthSmallest(root1, 1))  # Output: 1
print(kthSmallest(root2, 3))  # Output: 3