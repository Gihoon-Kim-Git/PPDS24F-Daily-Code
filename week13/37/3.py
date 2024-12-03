class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        row_strength = []
        for i, row in enumerate(mat):
            soldiers = sum(row)  
            row_strength.append((soldiers, i))  

        row_strength.sort(key=lambda x: (x[0], x[1]))

        weakest_rows = []
        for j in range(k):
            weakest_rows.append(row_strength[j][1])

        return weakest_rows