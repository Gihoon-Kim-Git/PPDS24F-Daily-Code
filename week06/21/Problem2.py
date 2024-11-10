# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")


def solution(A):
    # Implement your solution here
    ans = 0
    idx=1
    n = len(A)
    while idx < n-1:
        if A[idx] > 0:
            ans += A[idx]
            idx += 1
            # print("ans1",ans)
            # print("idx2",idx)
        elif (n-1)-idx <= 5:
            tempidx = idx
            for j in range((n-1)-idx):
                if A[idx + j] > A[tempidx]:
                    tempidx = idx + j
            ans += A[tempidx]
            idx = tempidx + 1
            # print("ans2",ans)
            # print("idx2",idx)
            break
        elif idx + 5 < n: 
            if A[idx] <= 0 and A[idx+1] <= 0 and A[idx+2] <= 0 and A[idx+3] <= 0 and A[idx+4] <= 0 and A[idx+5] <= 0 :
                tempidx = idx
                for j in range(1,6):
                    if A[idx+j] < A[tempidx] :
                        tempidx = idx+j
                ans += A[tempidx]
                idx = tempidx + 1
                # print("ans3",ans)
                # print("idx3",idx)
            else:
                idx+=1
                # print("ans4",ans)
                # print("idx4",idx)
        else:
            break
    ans += A[0] + A[n-1]
    # print("ans5",ans)
    # print("idx5",idx)
    return ans




