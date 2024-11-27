class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        return self.__DFTHelp(root, root.val, root.val)

    def __DFTHelp(self, root, big, small) -> int:
        if not root:
            return big - small
        big = max(root.val, big)
        small = min(root.val, small)
        
        #big, small에 현재 root val이 포함이 되기 때문에 left랑 right만 비교하면 됨
        ld = self.__DFTHelp(root.left, big, small)
        rd = self.__DFTHelp(root.right, big, small)

        return max(ld,rd)