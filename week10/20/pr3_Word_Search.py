from typing import List

class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        # m(x-axis) * n(y-axis) grid
        m = len(board[0])
        n = len(board)

        direction = [(1, 0), (-1, 0), (0, 1), (0, -1)]  # 상하좌우 이동 방향

        # Backtracking search function
        def search(a: int, b: int, cnt: int) -> bool:
            # 단어를 모두 찾았으면 True 반환
            if cnt == len(word):
                return True
            
            # 보드의 경계를 벗어나거나, 현재 문자가 일치하지 않으면 False 반환
            if a < 0 or a >= n or b < 0 or b >= m or board[a][b] != word[cnt]:
                return False

            # 방문한 셀을 '#'로 표시해 중복 방문 방지
            temp = board[a][b]
            board[a][b] = '#'

            # 상하좌우로 이동하여 다음 문자 탐색
            for dx, dy in direction:
                new_x, new_y = a + dx, b + dy
                if search(new_x, new_y, cnt + 1):  # 다음 문자를 찾으러 재귀 호출
                    return True

            # 탐색을 마친 후 셀의 값을 원래대로 복구
            board[a][b] = temp
            return False

        # 모든 셀을 시작점으로 탐색
        for i in range(n):
            for j in range(m):
                if search(i, j, 0):  # 단어의 첫 글자부터 시작
                    return True
        return False
