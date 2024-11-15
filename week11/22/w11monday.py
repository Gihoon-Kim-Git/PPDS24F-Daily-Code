class Solution(object):
    def isPalindrome(self, s):
        s = ''.join(c.lower() for c in s if c.isalnum())
        n = len(s)
        if n == 0:
            return True
        dp = [[False]*n for _ in range(n)]
        for i in range(n):
            dp[i][i] = True
        for i in range(n-1):
            dp[i][i+1] = (s[i] == s[i+1])
        for length in range(3, n+1):
            for i in range(n-length+1):
                j = i+length-1
                dp[i][j] = (s[i]==s[j]) and dp[i+1][j-1]
        return dp[0][n-1]