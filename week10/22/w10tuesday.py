class Solution(object):
    def stoneGameIX(self, stones):
       count = [0] * 3
       for s in stones:
           count[s % 3] += 1
           
       if count[0] % 2 == 0:
           return count[1] != 0 and count[2] != 0
       
       return abs(count[1] - count[2]) > 2