from functools import cache
from math import inf

class Solution:
    def getMoneyAmount(self, n: int) -> int:
        @cache
        def dp(l,r):
            if r-l<1: return 0
            ans=inf
            for choice in range((l+r)//2,r):
                ans=min(ans, choice + max( dp(l,choice-1),dp(choice+1,r) ) )
            return ans
        return dp(1,n)