class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        ans = dict()
        for i in range(len(mat)):
            ans[i] = mat[i].count(1)
        
        sorted_ans = sorted(ans.items(), key = lambda item: item[1])

        lst = []
        for i in range(k):
            lst.append(sorted_ans[i][0])
        
        return lst



