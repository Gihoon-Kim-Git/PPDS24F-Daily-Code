class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        stones.sort()
        while len(stones) >= 2:
            big = stones.pop()
            mid = stones.pop()
            if big > mid:
                stones.append(big - mid)
                stones.sort()
            else:
                stones.sort()
        
        if len(stones) == 1:
            return stones[0]
        else:
            return 0
