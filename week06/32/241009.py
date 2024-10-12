# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        result = 0
        q = deque()
        q.append(root)

        while q:
            cur = q.popleft()
            if (cur.left and not cur.left.left and not cur.left.right):
                result += cur.left.val
            if cur.left:
                q.append(cur.left)

            if cur.right:
                q.append(cur.right)

        return result