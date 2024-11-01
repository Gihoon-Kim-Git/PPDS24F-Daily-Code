"""문제
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.
"""

"""문제풀이
    1. values 저장하는 list 생성
    2. dfs_inorder로 방문하며 만나는 노드 val 저장
    3. return val[k-1]
"""

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution():
    def dfs(self, curNode, values):
        if curNode is None:
            return values
        left_values = self.dfs(curNode.left, values) if curNode.left else []
        right_values = self.dfs(curNode.right, values) if curNode.right else []
        return left_values + [curNode.val] + right_values
            
    def kthSmallest(self, root, k):
        values = self.dfs(root, [])
        return values[k-1]
    

## ------ 아래는 따로 values list를 저장하지 않고 진행하는 방법.

#보다 효율적인 코드 : count가 k에 도달하면 중단.
    ## inorder traversal 중 k번째 작은 요소 찾으면 그 값이 self.result에 저장됨. 이후 재귀적으로 다른 노드 방문하기 전, 이 조건을 검사해서 더이상의 탐색을 하지 않도록 함. 
class Solution:
    def kthSmallest(self, root, k):
        self.count = 0
        self.result = None
        
        def inorder(node):
            if not node or self.result is not None:
                return
            
            inorder(node.left)
            self.count += 1
            if self.count == k:
                self.result = node.val
                return
            inorder(node.right)
        
        inorder(root)
        return self.result
    

# class 변수 없이 구현 (중위 순회 동안 count가 k에 도달하면 해당 노드의 값이 result[0]에 저장되고, 이후의 모든 순회는 조기에 종료)
class Solution:
    def kthSmallest(self, root, k):
        def inorder(node, count, result):
            if not node or result[0] is not None:
                return count, result
            
            # 왼쪽 자식 노드 방문
            count, result = inorder(node.left, count, result)
            if result[0] is not None:
                return count, result
            
            # 현재 노드 처리
            count += 1
            if count == k:
                result[0] = node.val
                return count, result
            
            # 오른쪽 자식 노드 방문
            return inorder(node.right, count, result)
        
        # count 초기화, result를 리스트로 초기화 (참조 유지를 위해)
        result = [None]
        count = 0
        _, result = inorder(root, count, result)
        return result[0]
