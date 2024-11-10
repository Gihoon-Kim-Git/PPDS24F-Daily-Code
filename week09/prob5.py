# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def kthSmallest(self, root, k):
        """
        :type root: Optional[TreeNode]
        :type k: int
        :rtype: int
        """
        stack = []
        current = root
        count = 0
        
        while current or stack:
            # 왼쪽 서브트리를 모두 탐색
            while current:
                stack.append(current)
                current = current.left
            
            # 스택에서 노드를 꺼내어 방문
            current = stack.pop()
            count += 1
            if count == k:
                return current.val
            
            # 오른쪽 서브트리 탐색
            current = current.right
        
        # k가 트리의 노드 수를 초과하는 경우 (문제 조건상 발생하지 않음)
        return -1
        
        