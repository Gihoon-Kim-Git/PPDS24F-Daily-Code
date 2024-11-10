"""<문제>
You are given integers K, M and a non-empty array A consisting of N integers. Every element of the array is not greater than M.

You should divide this array into K blocks of consecutive elements. The size of the block is any integer between 0 and N. Every element of the array should belong to some block.

The sum of the block from X to Y equals A[X] + A[X + 1] + ... + A[Y]. The sum of empty block equals 0.

The large sum is the maximal sum of any block.

For example, you are given integers K = 3, M = 5 and array A such that:

  A[0] = 2
  A[1] = 1
  A[2] = 5
  A[3] = 1
  A[4] = 2
  A[5] = 2
  A[6] = 2
The array can be divided, for example, into the following blocks:

[2, 1, 5, 1, 2, 2, 2], [], [] with a large sum of 15;
[2], [1, 5, 1, 2], [2, 2] with a large sum of 9;
[2, 1, 5], [], [1, 2, 2, 2] with a large sum of 8;
[2, 1], [5, 1], [2, 2, 2] with a large sum of 6.
The goal is to minimize the large sum. In the above example, 6 is the minimal large sum.

Write a function:

def solution(K, M, A)

that, given integers K, M and a non-empty array A consisting of N integers, returns the minimal large sum.
"""
"""<constraint>
Write an efficient algorithm for the following assumptions:

N and K are integers within the range [1..100,000];
M is an integer within the range [0..10,000];
each element of array A is an integer within the range [0..M]."""

"""문제풀이
    1. solution (minimual large sum을 반환)
      - 이진탐색 범위 : low (max_element), high (A배열 sum)
      - while 문
          mid = (low+high)/2
      -   mid값 기준으로 isValidPartition(K,mid,A)== true
              => yes : high를 mid로 수정. 더 작은 mid를 만들 수 있도록
              => no : low를 더 키우기...
      - return low (while 탈출 시 low == high)
    2. isValidPartition(K, mid, A) : mid 값이 block의 최대합(large sum)일 때, 배열을 K개로 나누는 것이 가능한지 확인하는 함수 (가능하면 true else false)
      -> 배열 원소를 더해가면서 mid값을 초과할 때마다 새로운 block을 만듦. 
      -> A 순회가 끝났을 때, 생긴 block 갯수 <= K 이면 valid (그럼 다음 binary search 해야함. 더 작은 값을 기준으로 K block 만들 수 있는지). block 갯수 > K 이면 false 
"""

def isValidPartition(K, max_sum, A) :
    current_block = 1
    current_block_sum = 0
    
    #배열 순회하면서 필요한 block 갯수 산출
    for i in range(len(A)):
        if current_block_sum + A[i] > max_sum :
            current_block += 1
            current_block_sum = A[i]
        else :
            current_block_sum += A[i]
    if current_block > K : 
      return False  
    else:
      return True
    
def solution(K,M,A) :
    low = max(A) # block에 하나의 숫자만 들어갈 때
    high = sum(A) # block에 모든 element가 들어갈 때
    
    result = high
        
    while low <= high :
        mid = (low + high) // 2 

        if isValidPartition(K, mid, A) == True: 
          # find smaller mid
            result = mid
            high = mid-1
        else :
          # find larger mid
            low = mid + 1
    
    return result
  

if __name__ == "__main__" :
  print(solution(3, 5, [2, 1, 5, 1, 2, 2, 2])) #6
  print(solution(1, 1, [0])) #0