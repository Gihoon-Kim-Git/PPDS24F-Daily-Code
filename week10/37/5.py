class Solution:
    def minimumOneBitOperations(self, n: int) -> int:
        ans=0
        while n:
            ans=-ans-(n^(n-1))
            n&=n-1
        return abs(ans)    