"""<문제>
A non-empty array A consisting of N integers is given. The product of triplet (P, Q, R) equates to A[P] * A[Q] * A[R] (0 ≤ P < Q < R < N).

For example, array A such that:
    A[0] = -3
    A[1] = 1
    A[2] = 2
    A[3] = -2
    A[4] = 5
    A[5] = 6
contains the following example triplets:

(0, 1, 2), product is −3 * 1 * 2 = −6
(1, 2, 4), product is 1 * 2 * 5 = 10
(2, 4, 5), product is 2 * 5 * 6 = 60
Your goal is to find the maximal product of any triplet.

Write a function:

def solution(A)

that, given a non-empty array A, returns the value of the maximal product of any triplet.


Write an efficient algorithm for the following assumptions:

N is an integer within the range [3..100,000];
each element of array A is an integer within the range [−1,000..1,000].
"""

"""풀이
    1. 그냥 sort한 다음
    2. 아래 경우에 해당하는 것을 찾는다.
        (1) - 값 2개 * A의 맨 오른쪽 요소 : -값들이 더 높은 절댓값을 가지는 경우.
        (2) A의 맨 오른쪽 요소 3개
"""

def solution(A):
    A.sort()
    #2-(1)
    with_2minus_product = A[-1]
    for i in range(2):
        with_2minus_product *= A[i]
    #2-(2)
    last_3_product = 1
    for j in range(len(A)-1, len(A)-4, -1):
        last_3_product *= A[j]
    
    return with_2minus_product if with_2minus_product > last_3_product else last_3_product 



###----------번외 : 최대곱과 그 때의 index까지 같이 반환해야 한다면...? ---------------------

def solution_with_index(A):
    #(원소, index)를 저장한 리스트 생성
    indexed_A = [(A[i], i) for i in range(len(A))]
    
    #배열을 원소에 따라 정렬
    indexed_A.sort(key = lambda x : x[0])
    
    #가장 큰 세 값과 그 인덱스 (후보 1,2)
    max_product1 = indexed_A[-1][0] * indexed_A[-2][0] * indexed_A[-3][0]
    indices1 = (indexed_A[-1][1], indexed_A[-2][1], indexed_A[-3][1])
    
    max_product2 = indexed_A[0][0] * indexed_A[1][0] * indexed_A[-1][0]    
    indices2 = (indexed_A[0][1], indexed_A[1][1], indexed_A[-1][1])
    
    # 더 큰 곱을 가진 인덱스를 반환
    if max_product1 > max_product2 :
        return indices1
    else :
        return indices2

# 테스트 케이스
if __name__ == "__main__":
    A = [-3, 1, 2, -2, 5, 6]
    print(solution_with_index(A))  # 예상 출력: (2, 4, 5) 또는 (5, 4, 2)