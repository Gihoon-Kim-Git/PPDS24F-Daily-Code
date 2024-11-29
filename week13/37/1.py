class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        while len(stones) > 1:
            stones.sort()
            heaviest = stones.pop()
            second_heaviest = stones.pop()
            if heaviest != second_heaviest:
                stones.append(heaviest - second_heaviest)
        return stones[0] if stones else 0
