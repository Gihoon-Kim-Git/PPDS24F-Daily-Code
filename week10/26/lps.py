def lps(s: str) -> int:
  #init dp array
  N = len(s)
  dp = [[-1 for _ in range(N)] for _ in range(N)] 
  
  def lps_recursive(i: int, j: int) -> int:
    # base cases
    if i == j:
      return 1 
    if i > j:
      return 0 
    if i + 1 == j and s[i] == s[j]:
      return 2 

    # check memo
    if dp[i][j] != -1:
      return dp[i][j]

    # recuresion
    if s[i] == s[j]:
      dp[i][j] = lps_recursive(i + 1, j - 1) + 2
    else:
      dp[i][j] = max(lps_recursive(i + 1, j), lps_recursive(i, j - 1))

    return dp[i][j] # write into memo

  return lps_recursive(0, N - 1)