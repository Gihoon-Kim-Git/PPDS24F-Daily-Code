# TieRopes
def solution(K, A):
    count = 0  # K 이상인 로프의 개수
    current_length = 0  # 현재 묶고 있는 로프의 길이

    for length in A:
        current_length += length  # 현재 로프 길이에 추가
        if current_length >= K:  # K 이상이면
            count += 1  # 카운트 증가
            current_length = 0  # 현재 길이 초기화

    return count

# Example test case
K = 4
A = [1, 2, 3, 4, 1, 1, 3]
print(solution(K, A))