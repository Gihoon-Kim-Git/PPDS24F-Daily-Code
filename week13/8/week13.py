#1. Last stone weight
class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        stones.sort(reverse = True)

        while len(stones) > 1:
            if stones[0] == stones[1]:
                stones = stones[2:]
            else:
                stones[1] = stones[0] - stones[1]
                stones = stones[1:]
                stones.sort(reverse = True)
        
        if len(stones) == 0:
            return 0
        else:
            return stones[0]
        



#2. Car Pooling
class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        events = []

        # Step 1: 트립을 이벤트로 변환
        for person, start, end in trips:
            events.append((start, person))  # 탑승 이벤트
            events.append((end, -person))  # 하차 이벤트

        # Step 2: 이벤트를 시간 기준으로 정렬
        # 동일 시간에서는 하차 이벤트를 먼저 처리 (-person이 +person보다 앞서도록)
        events.sort(key=lambda x: (x[0], x[1]))

        # Step 3: 이벤트 처리하며 용량 체크
        current_capacity = 0
        for time, change in events:
            current_capacity += change  # 승객 수 업데이트

            # 차량 용량 초과 체크
            if current_capacity > capacity:
                return False

        # 용량 초과 없이 처리 완료
        return True




#3. The K weakest rows in a matrix
class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        ans = dict()
        for i in range(len(mat)):
            ans[i] = mat[i].count(1)
        
        sorted_ans = sorted(ans.items(), key = lambda item: item[1])

        lst = []
        for i in range(k):
            lst.append(sorted_ans[i][0])
        
        return lst



#4. maximum depth of binary tree
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if root == None:
            return 0
        
        left_depth = self.maxDepth(root.left)
        right_depth = self.maxDepth(root.right)

        return max(left_depth, right_depth)+1
    


#5. maximum difference between node and ancestor
class Solution:
    def helper(self, node, max_val, min_val):
        if not node:
            return max_val - min_val
        
        # Update max and min values
        max_val = max(max_val, node.val)
        min_val = min(min_val, node.val)
        
        # Recurse for left and right subtrees
        left_diff = self.helper(node.left, max_val, min_val)
        right_diff = self.helper(node.right, max_val, min_val)
        
        # Return the maximum difference found
        return max(left_diff, right_diff)
    
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        return self.helper(root, root.val, root.val)