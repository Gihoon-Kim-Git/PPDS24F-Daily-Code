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
        


