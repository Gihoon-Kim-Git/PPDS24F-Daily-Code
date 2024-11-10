class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        stack = []
        current = root

        while True:
            while current:
                stack.append(current)
                current = current.left
            
            current = stack.pop()
            k -= 1
            
            if k == 0:
                return current.val
            
            current = current.right