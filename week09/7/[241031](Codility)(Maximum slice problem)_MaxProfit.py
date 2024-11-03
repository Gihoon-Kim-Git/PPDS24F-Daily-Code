"""문제 : Given a log of stock prices compute the maximum possible earning.

An array A consisting of N integers is given. It contains daily prices of a stock share for a period of N consecutive days. If a single share was bought on day P and sold on day Q, where 0 ≤ P ≤ Q < N, then the profit of such transaction is equal to A[Q] − A[P], provided that A[Q] ≥ A[P]. Otherwise, the transaction brings loss of A[P] − A[Q].

For example, consider the following array A consisting of six elements such that:
    A[0] = 23171
    A[1] = 21011
    A[2] = 21123
    A[3] = 21366
    A[4] = 21013
    A[5] = 21367
If a share was bought on day 0 and sold on day 2, a loss of 2048 would occur because A[2] − A[0] = 21123 − 23171 = −2048. If a share was bought on day 4 and sold on day 5, a profit of 354 would occur because A[5] − A[4] = 21367 − 21013 = 354. Maximum possible profit was 356. It would occur if a share was bought on day 1 and sold on day 5.

Write a function,
    def solution(A)
that, given an array A consisting of N integers containing daily prices of a stock share for a period of N consecutive days, returns the maximum possible profit from one transaction during this period. The function should return 0 if it was impossible to gain any profit.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..400,000];
each element of array A is an integer within the range [0..200,000].
"""

"""문제풀이1 :Naive
    1. max값 찾고 min 값 찾아서 max-min 하면 되지 않나.? 안됨. 여기서는 시간조건이 있음. A-B이면, B가 A보다 index 상으로 앞서야 한다는 조건.
    2. 이 문제를 풀려면 cur index 기준으로 min값을 갱신하는 과정이 필요하겠다.
    3. for 문을 돌면서 maxprofit과 cur_index를 함께 update하자. 
"""
#%%
def solution(A):
    if len(A)== 0 : 
        return 0
    #cur_min을 관리하는 변수
    cur_min = A[0]
    maxProfit = 0 # The function should return 0 if it was impossible to gain any profit.
    
    for i in range(1, len(A)):
        #현재자리에서 cur_min을 빼면 maxprofit
        if maxProfit < A[i]-cur_min:
            maxProfit = A[i]-cur_min
        #다음자리에서 활용할 cur_min을 필요시 update
        if cur_min > A[i] :
            cur_min = A[i]
    
    return maxProfit

print(solution([23171,21011,21123,21366,21013,21367])) #356
# %%
