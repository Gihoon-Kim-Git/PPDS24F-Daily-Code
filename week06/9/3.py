from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        self.result = [0]
        self.travel(root)
        return sum(self.result)

    def left_is_leaf(self, node: TreeNode):
        left_node = node.left
        if not left_node.left and not left_node.right:
            return True
        return False

    def travel(self, node: TreeNode):
        if not node:
            return
        
        if node.left and self.left_is_leaf(node):    
            self.result.append(node.left.val)
            self.travel(node.right)
        
        else :
            self.travel(node.left)
            self.travel(node.right)
            
    






if __name__ == '__main__':
    sol = Solution()
    root = TreeNode(3)
    # root.left = TreeNode(9)
    # root.right = TreeNode(20)
    # root.right.left = TreeNode(15)
    # root.right.right = TreeNode(7)
    print(sol.sumOfLeftLeaves(root))