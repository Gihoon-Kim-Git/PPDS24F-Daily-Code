
# Definition for a Node.
class Node:
    def __init__(self, val: int = None, children: list['Node'] = None):
        self.val = val
        self.children = children

from collections import deque

class Solution:
    def maxDepth(self, root: 'Node') -> int:
        # Make a stack of nodes
        # Increase cnt + 1 whenever it calls children
        
        # No.. go recursive
        if not root : return 0
        elif not root.children : return 1
        lst = deque()
        def helper(node,cnt):
            cnt+=1
            if not node.children :
                lst.append(cnt)
                return
            else :
                n = len(node.children)
                for j in range(n):
                    helper(node.children[j],cnt)

        for i in range(len(root.children)):
            cnt = 1
            helper(root.children[i],cnt)
        return max(lst)
        



