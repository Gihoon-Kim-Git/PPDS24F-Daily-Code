"""Given the root of a binary tree, find the maximum value v for which there exist different nodes a and b where v = |a.val - b.val| and a is an ancestor of b.

A node a is an ancestor of b if either: any child of a is equal to b or any child of a is an ancestor of b."""

"""Constraints:
    The number of nodes in the tree is in the range [2, 5000].
    0 <= Node.val <= 105"""
    
"""아이디어
    Helper함수 : 현재 Node(root)에서 모든 자식들과의 diff를 비교하고 max_diff값을 반환.하는 함수
        while 자녀가 있는 동안
            cur을 갱신하면서 
            abs(root-cur) 값을 계산.
            만약 abs(root-cur) 값이 max_diff보다 더 크면 max_diff를 갱신한다.

    BFS(root)에 이면 내 하위 Node를 다 볼 수 있으니까...
    BFS하면서 max_dif를 update하는 방식으로 해야겠다.
"""

from collections import deque

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution(object):
    def maxAncestorDiff(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        def cur_max_diff(cur_top):
            max_dif = 0

            q = deque([cur_top])
            while q :
                cur = q.popleft()
                
                if abs(cur_top.val - cur.val) > max_dif :
                    max_dif = abs(cur_top.val - cur.val)
                
                if cur.left :
                    q.append(cur.left)
                if cur.right :
                    q.append(cur.right)
            
            return max_dif
        
        max_difference= 0
        
        q = deque([root])
        while q:
            cur_node = q.popleft()
            cur_max = cur_max_diff(cur_node)
            if cur_max > max_difference :
                max_difference = cur_max
                
            if cur_node.left :
                q.append(cur_node.left)
            if cur_node.right :
                q.append(cur_node.right)
        
        return max_difference
        

# [다른 방법1] self.diff + DFS 활용 root->leaf 까지의 path 하나 당 (big, small) 추적-----------------------------------------------------------------------------------

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution(object):
    def maxAncestorDiff(self, root):
        if not root:
            return 0
        self.diff = 0 #트리 전체에서 발견된 최대 차이를 저장하는 변수
        self.helper(root, root.val, root.val)
        return self.diff
    
    def helper(self, root, min_val, max_val): #재귀적으로 트리 탐색하면서 각 노드에서의 최소값, 최대값 업데이트, 최대 차이 계산
        if not root: #현재 노드가 None이면 재귀호출 종료
            return
        # 현재노드의 값과 최소값 / 또는 현재노드의 값과 최대값 차이를 계산해서 self.diff update
        self.diff = max(self.diff, max(abs(min_val - root.val), abs(max_val - root.val)))
        #현재 노드값을 활용해서 min_val 또는 max_val 업데이트
        min_val = min(min_val, root.val)
        max_val = max(max_val, root.val)
        #왼쪽 자식과 오른쪽 자식에 대해 재귀적으로 helper함수 호출
        self.helper(root.left, min_val, max_val)
        self.helper(root.right, min_val, max_val)



# [다른방법 2] DFS활용-------------------------------------------------------

class Solution(object):
    def maxAncestorDiff(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        return self.helper(root, root.val, root.val)

    def helper(self, r, mn, mx): #return으로 max_diff값을 반환하는 형태.
        if not r:
            return mx - mn # 더이상 내려갈 자식이 없을 때 해당 경로에서의 max_diff 반환.
        mn = min(mn, r.val)
        mx = max(mx, r.val)

        left_diff = self.helper(r.left, mn, mx)
        right_diff = self.helper(r.right, mn, mx)

        return max(left_diff, right_diff)