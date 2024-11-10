# subproblem

class Solution(object):
    def stoneGameIX(self, stones):
        """
        :type stones: List[int]
        :rtype: bool
        """
        if sum(stones) % 3 == 0:
            return True
        else:
            return False