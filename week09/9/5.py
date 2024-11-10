
class Solution(object):
    def kthSmallest(self, root, k):
        ord = []
        def inorder(v):
            if not v:
                return
            inorder(v.left)
            ord.append(v.val)
            inorder(v.right)

        inorder(root)

        return ord[k-1]