# week 10

# Tuesday. [Stone Game IX](https://leetcode.com/problems/stone-game-ix/description/)

class Solution:
    def stoneGameIX(self, stones: List[int]) -> bool:
        stones = [v % 3 for v in stones]
        
        d = defaultdict(int)
        for v in stones:
            d[v] += 1
        
        while d[1] >= 2 and d[2] >= 2:
            d[2] -= 1
            d[1] -= 1
        
        if d[0] % 2 == 0: # number of 0s will not influent the result
            if (d[1] == 1 and d[2] >= 1) or (d[2] == 1 and d[1] >= 1):
                return True
        else:
            if (d[1] == 0 and d[2] >= 3) or (d[2] == 0 and d[1] >= 3):
                return True
            if (d[1] == 1 and d[2] >= 4) or (d[2] == 1 and d[1] >= 4):
                return True

        return False