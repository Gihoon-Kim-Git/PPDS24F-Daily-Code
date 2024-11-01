"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution(object):
    def maxDepth(self, root):
        """
        :type root: Node
        :rtype: int
        """
        if root is None:
            return 0

        to_visit = deque([(root, 1)])
        visited = []
        while to_visit:
            curr, curr_depth = to_visit.popleft()
            for child in curr.children:
                    to_visit.append((child, curr_depth + 1))
        return curr_depth

        