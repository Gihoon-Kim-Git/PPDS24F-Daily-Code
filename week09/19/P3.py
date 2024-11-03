class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children

class Solution(object):
    def maxDepth(self, root):
        return self.maxDepthHelp(root, 1)
    
    def maxDepthHelp(self, root, depth):
        if root is None:
            return 0
        maxD = depth
        if root.children is not None:
            for child in root.children:
                childD = self.maxDepthHelp(child, depth+1)
                maxD = max(childD, maxD)
        return maxD

if __name__ == "__main__":
    root = Node(1, [Node(3, [Node(5), Node(6)]), Node(2), Node(4)])
    result = Solution()
    print(result.maxDepth(root))