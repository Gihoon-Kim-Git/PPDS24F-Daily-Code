import heapq
from typing import List

class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        # heapq는 기본적으로 min-heap만을 지원함
        # max-Heap을 사용하기 위해 stones 리스트의 모든 값을 음수로 변환
        stones = [-stone for stone in stones]
        # 리스트를 힙 구조로 변환: pop시 제일 큰 값부터 나오게 됨
        heapq.heapify(stones)
        
        # 힙에 돌이 하나 이상 남아 있는 동안 가장 무거운 두 개의 돌을 꺼내서 check
        while len(stones) > 1:
            heaviest = -heapq.heappop(stones)
            second_heaviest = -heapq.heappop(stones)
            
            # 두 돌의 무게가 다를 경우 새로운 돌을 힙에 추가, 무게가 같은 경우 그대로 삭제
            if heaviest != second_heaviest:
                new_stone = heaviest - second_heaviest
                heapq.heappush(stones, -new_stone)
        
        # 힙에 남아 있는 돌이 있다면 그 무게를 반환하고, 없다면 0을 반환
        return -stones[0] if stones else 0
