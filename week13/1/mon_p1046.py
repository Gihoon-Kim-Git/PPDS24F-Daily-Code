class Solution(object):
    def lastStoneWeight(self, stones):
        """
        :type stones: List[int]
        :rtype: int
        """
        # f1. pop heaviest two stones
        # f2. compare two stones and append (or not)

        # case 1. len(stones) > 1: resume games
        while len(stones) > 1: 
            first = max(stones) # int
            stones.remove(first) # [2,7,4,1,1]
            second = max(stones) # int
            stones.remove(second) # [2,4,1,1]

            diff = abs(first - second) # int
            if diff > 0: 
                stones.append(diff)


        # case 2: len(stones)==0 or len(stones)==1: end games            
        return stones[0]
