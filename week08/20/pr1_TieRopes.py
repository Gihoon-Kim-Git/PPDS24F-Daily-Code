def solution(K, A):
    # Implement your solution here
    cnt = 0
    curr = 0
    for x in A:
        curr +=x
        if curr >= K:
            cnt+=1
            curr=0
    return cnt