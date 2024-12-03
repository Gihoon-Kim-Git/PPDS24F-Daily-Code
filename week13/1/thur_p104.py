# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def maxDepth(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """        
        depth_list = []
        def count_depth(root, depth):
            if root is not None:
                depth += 1
                # print(root.val)
                count_depth(root.left, depth)
                count_depth(root.right, depth)
                
            else:
                depth_list.append(depth)
                # print(depth)

        count_depth(root, 0)

        return max(depth_list)