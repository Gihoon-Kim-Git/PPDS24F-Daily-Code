# Last Stone in Python
class Solution(object):
    def lastStoneWeight(self, stones):
        """
        :type stones: List[int]
        :rtype: int
        """
        stones.sort()
        while stones:
            x = stones.pop()
            if not stones:
                return x
            else:
                y = stones.pop()
                if x != y:
                    stones.append(x-y)
                    stones.sort()
        return 0

stones = [2,7,4,1,8,1]
sol = Solution()
print(sol.lastStoneWeight(stones))

