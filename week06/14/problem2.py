## Tuesday. [NumberSolitaire](https://app.codility.com/programmers/lessons/17-dynamic_programming/number_solitaire/)

def solution(A):
    N = len(A)
    answer = [A[0]] * (N + 6)

    for i in range(1, N):
        answer[i + 6] = max(answer[i : i + 6]) + A[i]

    return answer[-1]

# print(solution([1, -2, 0, 9, -1, -2]))