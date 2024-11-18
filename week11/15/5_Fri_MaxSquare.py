from typing import List

class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        Row, Col = len(matrix), len(matrix[0])
        cache = {}

        def help(r, c):
            if r >= Row or c >= Col:
                return 0

            if (r, c) not in cache:
                down = help(r+1, c)
                right = help(r, c+1)
                diag = help(r+1, c+1)

                cache[(r, c)] = 0
                if matrix[r][c] == "1":
                    cache[(r, c)] = 1 + min(down, right, diag)
            
            return cache[(r, c)]
        
        help(0, 0)
        return max(cache.values()) ** 2