# week 13

# Wednesday. [The K Weakest Rows in a Matrix](https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/description/)

class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        hashm=[]
        for i in range(len(mat)):
            hashm.append([mat[i].count(1),i])
        hashm.sort()
        res=[]
        for i in range(k):
            res.append(hashm[i][1])
        return res
        