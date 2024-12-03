from typing import List

class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        n_row = len(mat)
        soldier = dict()
        for i, row in enumerate(mat):
            soldier[i] = sum(row)

        # value값을 기준으로 key값을 sorting
        sorted_soldier = sorted(soldier, key=lambda x:soldier[x], reverse=False)

        result = []        

        for i, key in enumerate(sorted_soldier):
            if i < k:
                result.append(key)
        return result

mat = [[1,1,0,0,0],
       [1,1,1,1,0],
       [1,0,0,0,0],
       [1,1,0,0,0],
       [1,1,1,1,1]]
k = 3

sol = Solution()
print(sol.kWeakestRows(mat, k))