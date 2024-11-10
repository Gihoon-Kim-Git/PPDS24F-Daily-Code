class Solution:
    def getMoneyAmount(self, n: int) -> int:
        # base case
        if n == 1:
            return 0 
        
        startingIdx = 1 if n%2==0 else 2
        selected = [i for i in range(startingIdx, n, 2)]
        selectedLen = len(selected)

        dp = [[0] * selectedLen for _ in range(selectedLen)]

        for i in range(selectedLen):
            dp[i][i] = selected[i]

        for l in range(2, selectedLen+1):
            for i in range(selectedLen-l+1):
                j = i+l-1
                dp[i][j] = float("inf")
                for k in range(i, j+1):
                    dp_left = dp[i][k-1] if k!=0 else 0
                    dp_right = dp[k+1][j] if k!=j else 0
                    dp[i][j] = min(dp[i][j], selected[k] + max(dp_left, dp_right))
        return dp[0][-1]
    
    





if __name__ == "__main__":

    n1 = 10 # 16
    n2 = 1 # 0
    n3 = 2 # 1

    sol = Solution()
    print(sol.getMoneyAmount(n1))
    print(sol.getMoneyAmount(n2))
    print(sol.getMoneyAmount(n3))

    # constraints: 1<= n <= 200
