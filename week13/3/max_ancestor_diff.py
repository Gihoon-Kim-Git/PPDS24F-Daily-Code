"""
Given the root of a binary tree, find the maximum value `v` for which there exist different nodes `a` and `b` such that:
  - `v = |a.val - b.val|`
  - `a` is an ancestor of `b`

Definition:
  A node `a` is an ancestor of `b` if:
    - Any child of `a` is equal to `b`, or
    - Any child of `a` is an ancestor of `b`.

Examples:
1. Input: root = [8,3,10,1,6,null,14,null,null,4,7,13]
   Output: 7
   Explanation:
     - Various ancestor-node differences include:
       |8 - 3| = 5
       |3 - 7| = 4
       |8 - 1| = 7
       |10 - 13| = 3
     - The maximum value is obtained by |8 - 1| = 7.

2. Input: root = [1,null,2,null,0,3]
   Output: 3
   Explanation:
     - Differences include:
       |1 - 2| = 1
       |2 - 0| = 2
       |2 - 3| = 1
       |1 - 0| = 1
       |1 - 3| = 3
     - The maximum value is 3.

Constraints:
  - The number of nodes in the tree is in the range [2, 5000].
  - 0 <= Node.val <= 10^5
"""
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# DFS: recursive function
# start from the root node and traverse binary tree
def dfs(node, min_val, max_val):
    # base case: reach leaf node -> return total maximum difference
    if not node:
        return max_val - min_val
    
    # pass state: maintain 2 variables
    # minimum value in the path until current node
    # maximum value in the path until current node

    # update state: for each node
    # maximum difference at current node: max(abs(node.val - min_val), abs(node.val - max_val))
    # update min_val & max_val with current node
    min_val = min(min_val, node.val)
    max_val = max(max_val, node.val)

    # recursive case: left and right children
    left_diff = dfs(node.left, min_val, max_val)
    right_diff = dfs(node.right, min_val, max_val)

    # return current maximum difference
    return max(left_diff, right_diff)

def maxAncestorDiff(root):
    # Initial call with the root value as both min and max
    return dfs(root, root.val, root.val)

def test():
    # Tree construction
    root = TreeNode(8)
    root.left = TreeNode(3)
    root.right = TreeNode(10)
    root.left.left = TreeNode(1)
    root.left.right = TreeNode(6)
    root.left.right.left = TreeNode(4)
    root.left.right.right = TreeNode(7)
    root.right.right = TreeNode(14)
    root.right.right.left = TreeNode(13)
    
    print(maxAncestorDiff(root))  # Output: 7

test()