# 404. Sum of Left Leaves
#
# Given the root of a binary tree, return the sum of all left leaves.
# A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.
#
# Example 1:
# Input: root = [3,9,20,null,null,15,7]
# Output: 24
# Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.
#
# Example 2:
# Input: root = [1]
# Output: 0
#
# Constraints:
# - The number of nodes in the tree is in the range [1, 1000].
# - -1000 <= Node.val <= 1000

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# class Solution:
#     def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:

# Function signature:
def sumOfLeftLeaves(root):
    
    if root is None:
        return 0
    
    # helper function: check if a node is a leaf (no children)
    def is_leaf(node):
        return node is not None and node.left is None and node.right is None

    ans = 0
    
    # check: left child exists, is leaf
    if root.left and is_leaf(root.left):
        # add left leaf value to the total sum (ans)
        ans += root.left.val

    # recursion
    # left subtree
    ans += sumOfLeftLeaves(root.left)
    # right subtree
    ans += sumOfLeftLeaves(root.right)

    return ans

# Test cases for sumOfLeftLeaves function

def test_sumOfLeftLeaves():
    # Example 1: root = [3,9,20,null,null,15,7]
    root1 = TreeNode(3)
    root1.left = TreeNode(9)
    root1.right = TreeNode(20, TreeNode(15), TreeNode(7))
    assert sumOfLeftLeaves(root1) == 24, "Test case 1 failed"  # 9 and 15 are left leaves

    # Example 2: root = [1]
    root2 = TreeNode(1)
    assert sumOfLeftLeaves(root2) == 0, "Test case 2 failed"  # No left leaves

    # Additional test case 1: root = [1, 2, 3, 4, 5]
    root3 = TreeNode(1)
    root3.left = TreeNode(2, TreeNode(4), TreeNode(5))
    root3.right = TreeNode(3)
    assert sumOfLeftLeaves(root3) == 4, "Test case 3 failed"  # 4 is the only left leaf

    # Additional test case 2: root = [1, null, 2]
    root4 = TreeNode(1)
    root4.right = TreeNode(2)
    assert sumOfLeftLeaves(root4) == 0, "Test case 4 failed"  # No left leaves

    # Additional test case 3: root = [-1, -2, -3, null, -4]
    root5 = TreeNode(-1)
    root5.left = TreeNode(-2, right=TreeNode(-4))
    root5.right = TreeNode(-3)
    assert sumOfLeftLeaves(root5) == 0, "Test case 5 failed"  # No left leaves

    # Additional test case 4: Larger tree with several left leaves
    root6 = TreeNode(10)
    root6.left = TreeNode(5, TreeNode(3), TreeNode(8))
    root6.right = TreeNode(15, TreeNode(12), TreeNode(18))
    assert sumOfLeftLeaves(root6) == 15, "Test case 6 failed"  # Left leaves: 3 and 12

    print("All test cases passed!")


# Run the test cases
test_sumOfLeftLeaves()