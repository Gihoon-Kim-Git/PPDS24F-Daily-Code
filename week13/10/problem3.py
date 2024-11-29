from collections import List

class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        
        row_strength = [(sum(row), idx) for idx, row in enumerate(mat)]
        sorted_rows = sorted(row_strength, key=lambda x: (x[0], x[1]))
        weakest_rows = [idx for _, idx in sorted_rows[:k]]
    
        return weakest_rows