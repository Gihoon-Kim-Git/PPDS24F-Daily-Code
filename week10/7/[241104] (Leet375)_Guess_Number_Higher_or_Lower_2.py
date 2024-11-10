"""문제
We are playing the Guessing Game. The game will work as follows:

    1. I pick a number between 1 and n.
    2. You guess a number.
    3. If you guess the right number, you win the game.
    4. If you guess the wrong number, then I will tell you whether the number I picked is higher or lower, and you will continue guessing.
    5. Every time you guess a wrong number x, you will pay x dollars. If you run out of money, you lose the game.
    6. Given a particular n, return the minimum amount of money you need to guarantee a win regardless of what number I pick.

Constraint: 
    1 <= n <= 200
"""
"""Hint : MinMax알고리즘 (turn이 돌아가는 game에서 활용하는 알고리즘)
    -- 각 숫자 선택이 틀렸을 경우, 나머지 범위에 대한 최대비용을 고려하고, 이 최대비용 중 최솟값을 선택하는 것.
    ▶ 이 문제는 MinMax알고리즘과 DP를 결합해서 풀이가능. 
        --MinMax
            1) 최악의 비용 계산 : 숫자 x가 틀렸을 때, 왼쪽범위 [low, x-1]과 오른쪽범위[x+1, high]에서 각각 게임을 계속했을 경우의 최악의 비용 계산. 왼쪽, 오른쪽에서 얻은 값 중 더 큰 값.
            2) 최소화 전략 : 1)에서 계산된 최악의 비용 중 최소가 되는 x를 선택. 즉, 모든 가능한 x 중에서 1)값이 가장 적은 x 찾기.
        --DP
            :DP 사용을 통해 subproblem의 결과를 저장해 중복계산 방지.
"""

"""수도코드1: Recursive
Function getMinimumCostToGuessNumber(n):
    - 정의: n개의 숫자 중에서 최소 비용으로 숫자를 맞추는 비용을 계산
    Create a recursive function called CalculateCost with parameters (start, end):
        - start와 end는 추측해야 할 숫자 범위를 나타냄
        If the range is empty or contains only one number:
            - 범위에 숫자가 없거나 하나만 있는 경우, 비용은 0이 됨
            Return 0
        Initialize minimumCost to a very large number:
            - 최소 비용을 매우 큰 수로 초기화
        For each number x in the range from start to end:
            - 시작부터 끝까지 범위 내의 각 숫자 x에 대해
            Calculate the cost if x is the wrong guess:
                - x가 잘못된 추측일 경우의 비용 계산
                - 왼쪽 범위(start to x-1)와 오른쪽 범위(x+1 to end) 중 더 큰 비용을 계산
            Add the cost of guessing x to the above cost:
                - 추측한 x의 비용을 위에서 계산한 비용에 더함            
            Update minimumCost if the current cost is lower:
                - 현재 비용이 더 낮을 경우, 최소 비용을 업데이트
        Return the minimumCost:
            - 계산된 최소 비용을 반환

    Call CalculateCost(1, n) to get the minimum cost for the range 1 to n:
        - 범위 1부터 n에 대한 최소 비용을 얻기 위해 CalculateCost를 호출
    Return the result of CalculateCost:
        - CalculateCost의 결과를 반환
"""

#1) Recursive (minmax) : Time limit exceeded
def getMoneyAmount(n):
    def dfs(low, high):
        if low >= high : 
            return 0
        min_cost = float('inf')
        for x in range(low, high):
            cost = x + max(dfs(low, x-1), dfs(x+1, high))
            min_cost = min(cost, min_cost)
        return min_cost
    return dfs(1,n)


"""수도코드2 : Top down DP
★ 범위 기반의 DP는 2차원 배열을 사용하는 것이 일반적임.각 범위의 시작점, 끝점.
Function CalculateMinimumCost(n):
    - 입력 n은 게임에서 사용될 최대 숫자를 나타냄
    Initialize a cache to store results of subproblems:
        - 하위 문제의 결과를 저장하기 위한 캐시(메모리) 초기화
    Define a recursive function called CostToGuess(start, end):
        - 숫자 범위를 입력으로 받아 최소 비용을 계산하는 재귀 함수 정의
        If start is greater than or equal to end:
            - 범위에 숫자가 하나도 없거나 하나만 있는 경우
            Return 0
            - 비용은 0
        If the result for (start, end) is in the cache:
            - 현재 범위에 대한 결과가 캐시에 이미 저장되어 있는지 확인
            Return the cached result
            - 저장된 결과를 반환
        Initialize minimumCost to infinity:
            - 최소 비용을 무한대로 초기화
        For each possible guess x from start to end:
            - 가능한 모든 추측 x에 대해 반복
            Calculate the maximum cost if x is not correct:
                - x가 틀렸을 경우에 대비하여 최대 비용 계산
                leftCost = Call CostToGuess(start, x-1)
                - 왼쪽 범위에 대한 비용
                rightCost = Call CostToGuess(x+1, end)
                - 오른쪽 범위에 대한 비용
            totalCost = x + max(leftCost, rightCost)
                - 추측 비용과 더 큰 비용을 합산
            Update minimumCost if totalCost is less:
                - totalCost가 현재의 minimumCost보다 작으면 업데이트
        Store the minimumCost in the cache for (start, end):
            - 계산된 최소 비용을 캐시에 저장
        Return minimumCost
            - 최소 비용 반환

    Call CostToGuess(1, n) to get the minimum cost from 1 to n:
        - 1부터 n까지의 최소 비용을 계산하기 위해 CostToGuess 호출
    Return the result from the recursive function
        - 재귀 함수로부터의 결과를 반환
"""

# 2) Top Down
def getMoneyAmount(n):
    n_mincost_result = [[-1 for _ in range(n+1)] for _ in range(n+1)]  #2차원으로 만들어야함!
    
    def dfs(low, high, n_result):
        if low >= high :
            return 0
        if n_result[low][high] != -1 :
            return n_result[low][high]
        min_cost = float('inf')
        for x in range(low, high):
            maximumcost = x + max(dfs(low, x-1, n_result), dfs(x+1, high, n_result))
            min_cost = min(min_cost, maximumcost)
        n_result[low][high] = min_cost
        return min_cost
    
    return  dfs(1, n, n_mincost_result)


"""수도코드3: Bottom-up DP
Function CalculateMinimumCost(n):
    - n: 게임에서 사용할 최대 숫자

    Initialize a 2D array dp where dp[i][j] will hold the minimum cost to guess from number i to j:
        - i에서 j까지 추측하는 데 필요한 최소 비용을 저장할 2차원 배열 dp를 초기화

    For each length from 2 to n (inclusive):
        - 길이 2부터 n까지 각 길이에 대해
        For each start from 1 to n-length+1:
            - 시작점 1부터 n-length+1까지
            Set end to start+length-1:
                - 끝점을 start+length-1로 설정
            Initialize dp[start][end] to a large number:
                - dp[start][end]를 큰 숫자로 초기화
            For each guess k from start to end:
                - start부터 end까지 각 추측 k에 대해
                Calculate the cost if guess k is wrong:
                    - 추측 k가 틀렸을 경우의 비용을 계산
                    cost = k + max(dp[start][k-1], dp[k+1][end] if k+1 <= end else 0)
                Update dp[start][end] with the minimum of its current value and cost:
                    - dp[start][end]를 현재 값과 비용 중 작은 값으로 업데이트

    Return dp[1][n]:
        - 1부터 n까지 추측하는 데 필요한 최소 비용 반환
"""

# 3) Bottom-up
def getMoneyAmount(n):
    mincostDP = [ [0 for _ in range(n+1)] for _ in range(n+1)]
    
    for length in range(2, n+1):
        for start in range(1, n-length+1 +1):
            end = start + length - 1
            mincostDP[start][end] = float('inf')
            for guess_num in range(start, end+1):
                # 오른쪽 범위가 유효한 경우와 그렇지 않은 경우를 분리하여 처리
                if guess_num == end:
                    cost = guess_num + mincostDP[start][guess_num-1]
                else:
                    cost = guess_num + max(mincostDP[start][guess_num-1], mincostDP[guess_num+1][end])
                    mincostDP[start][end] = min(cost, mincostDP[start][end])
    
    return mincostDP[1][n]
    
