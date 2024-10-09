""" 문제
binary tree의 root가 주어졌을 때, sum of all left leaves를 구하라.

left leaf : child가 없으면서, 부모 노드의 left child인 노드.
"""

""" constraint :
tree의 노드 개수 : 1~1000
-1000 <= node.val <= 1000"""

"""문제풀이1 : LevelOrder Traversal 활용
    1. Level order Traversal 하면서, cur.left가 leaf이면 sum에 추가하는 방식.
    2. isLeaf(Node) : Node.left, Node.right 모두  없으면 True. 아니면 False
"""

"""참고 : https://leetcode.com/problems/sum-of-left-leaves/solutions/1558055/c-python-recursive-iterative-dfs-bfs-morris-traversal-o-1-w-explanation-beats-100/"""

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

#풀이1
class Solution(object):
    def isLeaf(self, curNode) :
        if curNode.left == None and curNode.right == None:
            return True
        else :
            return False
        
    def sumOfLeftLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        leftSum = 0
        q = [root]
        while q:
            cur = q.pop(0)
            if cur.left != None and self.isLeaf(cur.left):
                leftSum += cur.left.val
            if cur.left :
                q.append(cur.left)
            if cur.right:
                q.append(cur.right)
        
        return leftSum
