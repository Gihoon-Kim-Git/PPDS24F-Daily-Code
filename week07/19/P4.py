# mid 값을 넘지 않고 K개 이내로 분할이 가능한 경우 최대값 출력, 아니면 -1 출력
def partition(K, mid, A):
    temp = 0
    part = []
    for i in A:
        if (temp+i <= mid):
            temp += i
        else:
            part.append(temp)
            temp = i
    part.append(temp)
    if (len(part) <= K):
        return max(part)
    return -1

def solution(K, M, A):
    upper = sum(A)
    lower = max(A)
    answer = []
    while (lower <= upper):
        mid = (upper + lower) // 2
        answer.append(partition(K, mid, A))
        if (answer[-1] != -1): # mid 값을 넘지 않고 K개 이내로 분할이 가능한 경우
            upper = mid - 1
        else:
            lower = mid + 1
            answer.pop()
    if (answer == []):
        return lower
    return min(answer)

if __name__ == "__main__":
    A = [2, 1, 5, 1, 2, 2, 2]
    print(solution(3, 5, A))
    B = [5, 3]
    print(solution(1, 10, B))
    C = [3, 4, 5, 6, 7, 8]
    print(solution(4, 10, C))