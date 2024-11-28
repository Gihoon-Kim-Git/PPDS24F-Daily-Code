"""Given the root of a binary tree, return its maximum depth.
    A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
"""

"""아이디어
    recursive하게.
    현재의 depth는 left_subtree, right_subtree의 depth 중 더 큰 값 + 1
    depth(cur) = max(depth(cur->left), depth(cur->right)) + 1
"""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
    def maxDepth(self, root):
        #Base  case
        if root == None:
            return 0
        
        #Recursive caes
        if root.left :
            left_depth = self.maxDepth(root.left)
        else :
            left_depth = 0
        if root.right:
            right_depth = self.maxDepth(root.right)
        else :
            right_depth = 0
        return max(left_depth, right_depth) + 1
    

#[다른 풀이]---------------------------------------------------------------------------
class Solution(object):
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        """문제해결전략
        1) edge : root만 있으면 max_depth = 1
        2) while (자녀가 있으면) root를 자녀로 바꿔주고, max_depth += 1
        3) recursive하게 푸는 것이 좋겟다. 
        def help_함수(root, max_depth):
            recursive case: //자녀가 있을 때
                max_depth += 1
                help_함수(root.left, max_depth)
                help_함수(root.right, max_depth)
            base case: // 자녀가 없을 때
                return
        4) max_depth를 global하게 정의
        """
        def deeper(root, max_depth):
            if root.left == None and root.right == None:
                return max_depth                
            else: 
                max_depth += 1
                if root.left != None:
                    depth_left = deeper(root.left, max_depth)
                else :
                    depth_left = max_depth
                if root.right != None:
                    depth_right = deeper(root.right, max_depth)
                else:
                    depth_right = max_depth
                max_depth = depth_left if depth_left > depth_right else depth_right
                return max_depth

        if not root:
            return 0
        else:
            maximum_depth = deeper(root, 1)

        return maximum_depth
        
        # return 0 if not root else max(self.maxDepth(root.left), self.maxDepth(root.right))+1