class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):
    def sumOfLeftLeaves(self, root):
        result = 0
        return self.sumOfLeftLeavesHelper(root, result)
    
    def sumOfLeftLeavesHelper(self, root, result):
        if root is None:
            return result
        if root.left is not None:
            if root.left.left is None and root.left.right is None: # left leaf check
                result += root.left.val
            else: # if node has no left leaf, go left
                result = self.sumOfLeftLeavesHelper(root.left, result)
        if root.right is not None:
            result = self.sumOfLeftLeavesHelper(root.right, result)
        return result

if __name__ == "__main__":
    root = TreeNode(3, TreeNode(9), TreeNode(20, TreeNode(15), TreeNode(7)))
    result = Solution()
    print(result.sumOfLeftLeaves(root))