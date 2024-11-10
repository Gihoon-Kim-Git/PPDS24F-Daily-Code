def solution(K, A):
    # Implement your solution here
    cnt=0
    current =0
    for i in range(len(A)):
        current += A[i]
        if current >= K:
            cnt+=1
            current =0
    return cnt