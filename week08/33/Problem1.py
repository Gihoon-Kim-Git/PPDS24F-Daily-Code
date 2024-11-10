# rope 길이가 array에 주어졌을때 K이상의 길이를 갖는 rope 수의 최대값 구하기
# 이 때 인접하는 rope는 묶을 수 있고, 이 경우 rope의 길이는 두 rope 길이의 합

def solution(K, A):
    # Implement your solution here
    ans = 0
    tie = 0
    for i in A:
        if i >= K:
            ans += 1
            tie = 0
        else:
            tie += i
            if tie >= K:
                ans += 1
                tie = 0
    return ans
