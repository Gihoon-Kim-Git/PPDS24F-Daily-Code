# Definition for a Node.
class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children if children is not None else []

# Solution class with the maxDepth method
class Solution(object):
    def maxDepth(self, root):
        """
        :type root: Node
        :rtype: int
        """
        queue = []
        if root:
            queue += [(root, 1)]
        maxDepth = 0
        for (node, depth) in queue:
            maxDepth = depth
            tmp = []
            for child in node.children:
                tmp += [(child, depth + 1)]
            queue += tmp
        return maxDepth

# Driver code to test the maxDepth function

# Creating a sample tree:
#        1
#      / | \
#     3  2  4
#    / \
#   5   6

node5 = Node(5)
node6 = Node(6)
node3 = Node(3, [node5, node6])
node2 = Node(2)
node4 = Node(4)
root = Node(1, [node3, node2, node4])

# Create an instance of the Solution class and find the maximum depth
solution = Solution()
print("Maximum depth of the tree:", solution.maxDepth(root))
