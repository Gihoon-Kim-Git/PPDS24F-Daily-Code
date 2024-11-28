"""
<Last Stone Weight>

You are given an array of integers stones where stones[i] is the weight of the ith stone.

We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:

If x == y, both stones are destroyed, and
If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
At the end of the game, there is at most one stone left.

Return the weight of the last remaining stone. If there are no stones left, return 0.
"""
import heapq

def lastStoneWeight(stones):
    """
    heapq 사용
    1. 가장 큰 값 2개 꺼냄. if weight same: 둘 다 제거, if not: 둘의 차이 heap에 다시 추가
    2. heap에 요소 1개 남으면 그 값 반환, 비어 있을 시 0 반환
    """
    max_heap = [-stone for stone in stones]    # max_heap 구현 위해 음수로 값 변환
    heapq.heapify(max_heap)

    while len(max_heap) > 1:
        stone1 = -heapq.heappop(max_heap)   # 원래 값으로 되돌리기 위해 - 붙임
        stone2 = -heapq.heappop(max_heap)

        if stone1 != stone2:
            heapq.heappush(max_heap, -(stone1-stone2))

    return -max_heap[0] if max_heap else 0

print(lastStoneWeight[2,7,4,1,8,1])   # 1
print(lastStoneWeight[1])   # 1
