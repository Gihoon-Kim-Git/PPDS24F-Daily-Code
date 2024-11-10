# 좌->우, 위->아래가 각각 오름차순으로 정렬된 2D matrix가 주어졌을 때
# target이 matrix에 있으면 true 없으면 false return

"""
다른 풀이 검색 결과
: row 0의 가장 오른쪽(가장 큰) 값과 target비교해서
  target보다 크면 왼쪽으로 작으면 아랫줄로 이동
"""

class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        for row in matrix:
            if target in row:
                return True
        return False
