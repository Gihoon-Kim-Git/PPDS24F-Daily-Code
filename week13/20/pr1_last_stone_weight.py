class Solution:
    def lastStoneWeight(self, stones: list[int]) -> int:
        while len(stones) > 1 :
            stones = sorted(stones)
            top1 = stones.pop() 
            top2 = stones.pop() 
            if top1 == top2 : continue
            else :
                top1 -= top2
                stones.append(top1)

        if len(stones) == 0 : return 0
        else : return stones[0]