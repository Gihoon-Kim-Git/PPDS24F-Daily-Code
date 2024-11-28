"""
<Maximum Depth of Binary Tree>

Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path 
from the root node down to the farthest leaf node. (root 포함, 마지막 leaf 포함)
"""

from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def buildTree(values):
    if not values: return None
    
    root = TreeNode(values[0])
    queue = deque([root])
    i = 1

    while queue and i < len(values):
        node = queue.popleft()

        if values[i] is not None:
            node.left = TreeNode(values[i])
            queue.append(node.left)
        i += 1

        if i < len(values) and values[i] is not None:  # Add right child
            node.right = TreeNode(values[i])
            queue.append(node.right)
        i += 1
        
    return root

def maxDepth(root):
    """
    Left subtree와 right subtree recursive하게 traverse
    Return: max(left depth, right depth) + 1      <- + 1 은 current node 포함
    """
    if not root: return 0

    left_depth = maxDepth(root.left)
    right_depth = maxDepth(root.right)

    return max(left_depth, right_depth) + 1

print(maxDepth(buildTree([3,9,20,None,None,15,7])))  # 3
print(maxDepth(buildTree([1,None,2])))    # 2