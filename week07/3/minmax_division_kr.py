"""
문제: K개의 연속된 블록으로 배열을 나누었을 때 가장 큰 블록의 합(large sum)을 최소화하기

- 정수 K(블록의 개수), M(배열의 원소의 최대값), 그리고 N개의 정수를 포함하는 배열 A가 주어집니다.
- 배열 A를 K개의 연속된 블록으로 나누어야 하며, 이때 각 블록의 합 중 **가장 큰 값(large sum)**을 최소화해야 합니다.

예시:
  K = 3, M = 5, A = [2, 1, 5, 1, 2, 2, 2]
  가능한 블록 나누기:
    - [2, 1], [5, 1], [2, 2, 2] → 가장 큰 합 = 6
    - [2, 1, 5], [], [1, 2, 2, 2] → 가장 큰 합 = 8
- 목표: 가장 큰 합을 최소화해야 하므로 위 예에서는 답이 6이 됩니다.

제약조건:
- N과 K는 1 이상 100,000 이하의 정수
- M은 0 이상 10,000 이하의 정수
- 배열 A의 각 원소는 0 이상 M 이하의 정수

접근 방식:
1. **이진 탐색**을 사용하여 최적의 large sum(가장 큰 블록 합)을 찾습니다.
2. large sum의 **하한(lower bound)**은 배열의 최대 원소입니다 (어떤 블록도 이보다 작은 합을 가질 수 없음).
3. large sum의 **상한(upper bound)**은 배열의 모든 원소의 합입니다 (전체 배열이 하나의 블록일 경우).
4. 주어진 "중간값(mid)"에 대해 배열을 K개의 블록으로 나눌 수 있는지 확인합니다.
5. mid 값에 따라 이진 탐색 범위를 조정합니다.

시간 복잡도: O(N * log(S)), 여기서 S는 배열 원소의 합입니다.
공간 복잡도: O(1) (추가 메모리 사용 없음)
"""

# 배열을 K개 이하의 블록으로 나누었을 때, 각 블록의 합이 max_sum 이하가 되도록 나눌 수 있는지 확인하는 함수
def can_divide(A, K, max_sum):
    current_sum = 0  # 현재 블록의 합
    blocks = 1  # 첫 번째 블록부터 시작

    # 배열의 각 원소를 순회하면서 블록을 형성합니다.
    for num in A:
        # 현재 블록에 num을 추가했을 때 max_sum을 초과하면 새로운 블록을 만듭니다.
        if current_sum + num > max_sum:
            blocks += 1  # 블록 수를 증가시킴
            current_sum = num  # 새로운 블록의 첫 번째 원소로 시작
        else:
            current_sum += num  # 현재 블록에 원소를 추가

        # 블록 수가 K를 초과하면 False를 반환 (mid 값이 너무 작아서 나눌 수 없는 경우)
        if blocks > K:
            return False

    # 주어진 max_sum으로 K개 이하의 블록으로 나눌 수 있으면 True 반환
    return True

# 이진 탐색을 사용하여 가장 작은 large sum을 찾는 함수
def solution(K, M, A):
    # 이진 탐색의 초기 범위 설정
    low = max(A)  # large sum의 최소값은 배열의 최대 원소값
    high = sum(A)  # large sum의 최대값은 배열 전체의 합

    # 이진 탐색 수행
    while low <= high:
        mid = (low + high) // 2  # 중간값(mid)을 large sum의 후보로 선택

        if can_divide(A, K, mid):
            # mid 값으로 나눌 수 있다면 더 작은 large sum을 시도
            high = mid - 1
        else:
            # mid 값으로 나눌 수 없다면 더 큰 large sum을 시도
            low = mid + 1

    # 이진 탐색이 종료되면 low 값이 최적의 large sum
    return low

# 예제 실행
K = 3
M = 5
A = [2, 1, 5, 1, 2, 2, 2]
print(solution(K, M, A))  # 출력: 6