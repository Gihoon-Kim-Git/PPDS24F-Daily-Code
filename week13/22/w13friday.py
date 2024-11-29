class Solution(object):
    def maxAncestorDiff(self, root):
        def helper(node, current_min, current_max):
            if not node:
                return current_max - current_min
            current_min = min(current_min, node.val)
            current_max = max(current_max, node.val)
            left_diff = helper(node.left, current_min, current_max)
            right_diff = helper(node.right, current_min, current_max)
            return max(left_diff, right_diff)
        return helper(root, root.val, root.val)
