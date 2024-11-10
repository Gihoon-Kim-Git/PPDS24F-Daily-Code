/*
문제 : Given a log of stock prices compute the maximum possible earning.

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
    int solution(vector<int> &A);

that, given an array A consisting of N integers containing daily prices of a stock share for a period of N consecutive days, returns the maximum possible profit from one transaction during this period. The function should return 0 if it was impossible to gain any profit.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..400,000];
each element of array A is an integer within the range [0..200,000].*/

/*풀이
    1. 현재 index에서 최대 profit을 구하려면 이전 index까지 중에 최솟값을 알아야 한다.
    2. 따라서 for문을 돌면서, cur_min과 maxprofit을 함께 update. (maxprofit 먼저 계산하고 cur_min update)
        이때, profit을 얻을 수 없으면 0을 반환하기 때문에 maxprofit의 초깃값은 0
    3. edge case는 len(A)==0
*/

#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> &A){
    if (A.size() == 0) return 0 ;
    int cur_min = A[0];
    int maxProfit = 0;

    for(auto a : A){
        if (a-cur_min > maxProfit) maxProfit = a-cur_min;
        if (cur_min > a) cur_min = a;        
    }

    return maxProfit;
}