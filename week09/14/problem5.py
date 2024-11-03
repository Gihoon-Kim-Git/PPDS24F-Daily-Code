# week 09

## Friday. [Kth Smallest Element in a BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/)

class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        values = []

        def dfs(node):
            if not node:
                return

            values.append(node.val)

            dfs(node.left)
            dfs(node.right)

        dfs(root)

        return sorted(values)[k - 1]