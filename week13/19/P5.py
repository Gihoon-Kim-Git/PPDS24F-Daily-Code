class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):
    def maxAncestorDiff(self, root):
        if root is None:
            return 0
        _, _, maxdiff = self.AncestorHelp(root)
        return maxdiff
        
    def AncestorHelp(self, root):
        minleft = root.val
        maxleft = root.val
        minright = root.val
        maxright = root.val
        difleft = 0
        difright = 0
        if root.left:
            minleft, maxleft, difleft = self.AncestorHelp(root.left)
        if root.right:
            minright, maxright, difright = self.AncestorHelp(root.right)
        minval = min(root.val, minleft, minright)
        maxval = max(root.val, maxleft, maxright)
        maxdiff = max(abs(root.val - minval), abs(root.val - maxval))
        maxdiff = max(maxdiff, difleft, difright)
        return minval, maxval, maxdiff

if __name__ == "__main__":
    root = TreeNode(8, TreeNode(3, TreeNode(1), TreeNode(6, TreeNode(4), TreeNode(7))), TreeNode(10, None, TreeNode(14, TreeNode(13))))
    result = Solution()
    print(result.maxAncestorDiff(root))
    root = TreeNode(1, None, TreeNode(2, None, TreeNode(0, TreeNode(3))))
    print(result.maxAncestorDiff(root))