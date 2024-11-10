class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):
    def kthSmallest(self, root, k):
        return self.kthSmallestHelp(root, [])[k-1]
    
    def kthSmallestHelp(self, root, tree):
        if root is None:
            return tree
        if root.left:
            tree = self.kthSmallestHelp(root.left, tree)
        tree.append(root.val)
        if root.right:
            tree = self.kthSmallestHelp(root.right, tree)
        return tree

if __name__ == "__main__":
    root = TreeNode(5, TreeNode(3, TreeNode(2, TreeNode(1)), TreeNode(4)), TreeNode(6))
    result = Solution()
    print(result.kthSmallest(root, 3))