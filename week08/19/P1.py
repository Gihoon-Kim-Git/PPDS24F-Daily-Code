def solution(K, A):
    count = 0
    temp = 0
    for i in A:
        if (temp+i < K):
            temp += i
        else:
            count += 1
            temp = 0
    return count

if __name__ == "__main__":
    A = [1,2,3,4,1,1,3]
    # A = [2]
    print(solution(4, A))