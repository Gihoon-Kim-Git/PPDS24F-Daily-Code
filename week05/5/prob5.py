def sum123(n: int) -> int:
    assert n > 0
    if n == 1:
        return 1
    elif n == 2:
        return 2
    elif n == 3:
        return 4
    else:
        return sum123(n-1) + sum123(n-2) + sum123(n-3)
    
def sum123_dp(n: int) -> int:
    answer = [0 for _ in range(n+1)]
    answer[1] = 1
    answer[2] = 2
    answer[3] = 4
    for i in range(4, n+1):
        answer[i] = answer[i-1] + answer[i-2] + answer[i-3]
    return answer[n]

def sum123_dp_optim(n: int) -> int:
    if n == 1:
        return 1
    elif n == 2:
        return 2
    elif n == 3:
        return 4
    else:
        answer = [0, 1, 2, 4]
        for i in range(4, n+1):
            answer[i%4] = sum(answer) - answer[i%4]
        return answer[i%4]


if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        n = int(input())
        # print(n)
        # print(sum123(n))
        # print(sum123_dp(n))
        print(sum123_dp_optim(n))
        # print()
