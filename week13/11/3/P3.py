class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        result = []
        queue = []
        l = len(mat[0])
        for i in range(len(mat)):
            j = 0
            count = 0
            while j < l and mat[i][j] == 1:
                count += 1
                j += 1
            queue.append([count, i])
        queue.sort(key = lambda x : (x[0], x[1]))

        for rank in range(k):
            result.append(queue[rank][1])
        return result
