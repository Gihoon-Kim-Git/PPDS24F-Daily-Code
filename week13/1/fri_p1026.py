# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def maxAncestorDiff(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        diff_list = []
        def count_diff(root, ancestor_list):
            if root is not None:
                diffs=[]
                for a_val in ancestor_list:
                    diffs.append(abs(a_val - root.val))
                diff_list.extend(diffs)
                
                new_ancestor_list = ancestor_list + [root.val]
                count_diff(root.left, new_ancestor_list)
                count_diff(root.right, new_ancestor_list)
                
            else:
                return None
                # print(depth)

        count_diff(root, [root.val])
        return max(diff_list)