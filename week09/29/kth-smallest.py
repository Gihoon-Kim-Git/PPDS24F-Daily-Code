# BST 성질 이용
# inorder로 정렬

class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def kthSmallest(root, k):
    """
    :type root: Optional[TreeNode]
    :type k: int
    :rtype: int
    """

    def inorder(node):
        if node is None: return

        inorder(node.left)
        res.append(node.val)
        inorder(node.right)

    res = []
    inorder(root)
    print(res)
    return res[k-1]
    
    


root = TreeNode(5)
root.left = TreeNode(3)
root.right = TreeNode(6)
root.left.left = TreeNode(2)
root.left.right = TreeNode(4)
root.left.left.left = TreeNode(1)
k = 3

print(kthSmallest(root,k))

