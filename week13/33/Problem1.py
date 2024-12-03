# 돌의 무게가 주어져 있을 때 가장 무거운 돌 두 개를 뽑아 무게 비교
# 이 때, 두 무게가 같으면 destorty 아니면 무게의 차를 다시 list에 저장
# 마지막으로 남아있는 돌의 무게 return. 남아있는 돌이 없으면 return 0

import heapq

class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        neg_stones = []
        for stone in stones:
            heapq.heappush(neg_stones, -stone)
        while(len(neg_stones) >= 2):
            heavy1 = heapq.heappop(neg_stones)
            heavy2 = heapq.heappop(neg_stones)
            heapq.heappush(neg_stones, heavy1-heavy2)
        
        if len(neg_stones) == 0:
            return 0
        else:
            return -neg_stones[0]
                