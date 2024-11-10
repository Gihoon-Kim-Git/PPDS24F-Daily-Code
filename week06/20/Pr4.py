class Solution:
    def reverseBits(self, n: int) -> int:
        # temp = str(n)
        # n = len(temp)
        # ans = 0
        # for i in range(n):
        #     if temp[i] == "1":
        #         ans += (2**n)
        # return ans
        ans = 0
        cnt = 31
        while n!=0 :
            if n&1 == 1:
                ans += 2**cnt
            cnt-=1
            n = n >> 1
        return ans