# n-ary tree의 max depth 구하기
# nonlocal 키워드!
"""
# Definition for a Node.
class Node:
    def __init__(self, val: Optional[int] = None, children: Optional[List['Node']] = None):
        self.val = val
        self.children = children
"""

class Solution:
    def maxDepth(self, root: 'Node') -> int:
        ans = 0
        
        def helper(node: 'Node', depth):
            nonlocal ans
            if not node:
                return
            ans = max(ans, depth)
            for child in node.children:
                helper(child, depth+1)

        helper(root, 1)
        
        return ans
