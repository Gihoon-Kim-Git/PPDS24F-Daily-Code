"""
<Maximum Difference Between Node and Ancestor>

Given the root of a binary tree, find the maximum value v for which 
there exist different nodes a and b where v = |a.val - b.val| and a is an ancestor of b.

A node a is an ancestor of b if either: any child of a is equal to b or any child of a is an ancestor of b.
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

def maxAncestorDiff(root):
    """
    Recursive traversal하며 그 path에서의 min과 max 저장
    Current node가 None이면 현재까지의 max_diff 반환
    """
    def helper(node, current_min, current_max):
        if not node: return current_max - current_min

        current_min = min(current_min, node.val)
        current_max = max(current_max, node.val)

        left_diff = helper(node.left, current_min, current_max)
        right_diff = helper(node.right, current_min, current_max)

        return max(left_diff, right_diff)

    return helper(root, root.val, root.val)



print(maxAncestorDiff(buildTree([8,3,10,1,6,None,14,None,None,4,7,13])))  # 7
print(maxAncestorDiff(buildTree([1,None,2,None,0,3])))    # 3