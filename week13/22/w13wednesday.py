class Solution(object):
    def kWeakestRows(self, mat, k):
        soldiers_count = [(sum(row), i) for i, row in enumerate(mat)]
        soldiers_count.sort(key=lambda x: (x[0], x[1]))
        return [index for _, index in soldiers_count[:k]]
