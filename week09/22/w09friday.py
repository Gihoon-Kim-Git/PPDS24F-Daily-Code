class Solution(object):
    def kthSmallest(self, root, k):
        def in_order_traversal(node):
            if not node:
                return []
            return in_order_traversal(node.left) + [node.val] + in_order_traversal(node.right)
        
        sorted_elements = in_order_traversal(root)
        return sorted_elements[k - 1]