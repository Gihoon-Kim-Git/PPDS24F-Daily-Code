# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
from collections import deque
class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        #Traversal - In-Order?
        visited = []
        s = deque([root])
        while s:
            curr = s[-1]
            if curr.left and curr.left.val not in visited :
                s.append(curr.left)
                continue
            else :
                visited.append(curr.val)
                s.pop()
                if len(visited) == k : return visited[-1]
                if curr.right:
                    s.append(curr.right)
        

