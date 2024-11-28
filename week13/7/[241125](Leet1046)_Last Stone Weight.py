"""You are given an array of integers stones where stones[i] is the weight of the ith stone.

We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:

    If x == y, both stones are destroyed, and
    If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
    At the end of the game, there is at most one stone left.

Return the weight of the last remaining stone. If there are no stones left, return 0."""

"""Constraints:
    1 <= stones.length <= 30
    1 <= stones[i] <= 1000"""

"""아이디어
    - 계속해서 무게가 가장 큰 것을 반환해야 하므로... heap 구조를 활용하면 좋겠다.
    python에서는 heapq가 minHeap이므로 -값을 붙여서 연산하자.
"""
"""수도코드
목표 : stones의 모든 값에 -를 붙여, heap 구조를 활용해 가장 작은 값을 두 개씩 뽑은 후, 조건에 따라 update하면서, heap사이즈가 1 또는 0이 되면 결과 반환.

1. heapq q 세팅 : stones의 모든 요소에 -값을 붙여서 heapq에 넣기. 
    (주의 : q가 빈 상태에서 heappush로 값을 넣어주어야 heap속성이 유지된 채로 들어감.)

2. q에서 두 개의 값을 차례로 빼서 조건에 따라 업데이트
    smaller = q.heappop()
    bigger = q.heappop()
    
    smaller-bigger != 0 이면 
        new_stone = smaller-bigger
        q.heappush(new_stone)

3. 2과정을 q의 크기가 1보다 큰 동안 반복진행.

4. 3과정이 끝났을 때, q의 상태에 따라 결과처리
    q의 크기가 1일때, 
        last = q.heappop()
        return -last #-값을 +로 바꿔서 반환
    q의 크기가 0일때
        return 0
"""

#%%
import heapq

class Solution(object):
    def lastStoneWeight(self, stones):
        """
        :type stones: List[int]
        :rtype: int
        """
        #heap에 stones의 모든 값을 -붙여서 넣기.
        q = []
        for stone in stones:
            heapq.heappush(q, -stone)
        
        #q의 크기가 1보다 큰 동안 q에서 2개씩 빼가며 업데이트
        while len(q) > 1 :
            smaller = heapq.heappop(q)
            bigger = heapq.heappop(q)
            if smaller-bigger != 0:
                new_stone = smaller-bigger
                heapq.heappush(q, new_stone)
                
        if len(q) == 1:
            last = heapq.heappop(q)
            return -last
        elif len(q) == 0:
            return 0

Sol1 = Solution()
stones = [2,7,4,1,8,1]
print(Sol1.lastStoneWeight(stones))
# %%
