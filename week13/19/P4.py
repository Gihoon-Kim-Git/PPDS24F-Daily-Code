class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):
    def maxDepth(self, root):
        if root is None:
            return 0
        return self.maxDepthHelp(root, 1)
        
    def maxDepthHelp(self, root, depth):
        left = depth
        right = depth
        if root.left:
            left = self.maxDepthHelp(root.left, depth+1)
        if root.right:
            right = self.maxDepthHelp(root.right, depth+1)
        return max(left, right)

if __name__ == "__main__":
    root = TreeNode(3, TreeNode(9), TreeNode(20, TreeNode(15), TreeNode(7)))
    result = Solution()
    print(result.maxDepth(root))
    root = TreeNode(1, None, TreeNode(2))
    print(result.maxDepth(root))