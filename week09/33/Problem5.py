# BST 주어졌을 때 k번째로 작은 value찾기

"""
DFT(Inorder)
"""

class Solution:
    def helper(self, root, ans):
        if not root:
            return
        
        self.helper(root.left, ans) 
        ans.append(root.val)
        self.helper(root.right, ans)

    def kthSmallest(self, root, k):
        ans = []
        self.helper(root, ans)

        return ans[k-1]
       
"""
위 코드가 더 빠름
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        count = 0
        ans = -1

        def helper(node):
            if not node:
                return
            nonlocal count, ans
            helper(node.left)
            count += 1
            if count == k:
                ans = node.val
                return
            helper(node.right)
        
        helper(root)
        
        return ans
"""