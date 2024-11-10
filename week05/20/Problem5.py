def func1(a:int) -> int:
    dp = [0] * (a+1)
    dp[0] = 1

    for i in range(1,a+1):
        if i >= 1:
            dp[i] = dp[i] + dp[i-1]
        if i >= 2:
            dp[i] = dp[i] + dp[i-2]
        if i >= 3:
            dp[i] = dp[i] + dp[i-3]
    return dp[a]

n = int(input()) # test case 수
for _ in range(n):
    a = int(input())
    print(func1(a))