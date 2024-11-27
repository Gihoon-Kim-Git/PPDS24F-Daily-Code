class Solution(object):
    def kWeakestRows(self, mat, k):
        """
        :type mat: List[List[int]]
        :type k: int
        :rtype: List[int]
        """
        # f1. count the sum of 1s in each row -> num
        # f2. compare each rows -> alphabet
        tmp = []
        for i, row in enumerate(mat):
            num = sum(row)
            idx = str(num) + '_' + str(i)
            tmp.append(idx)
        tmp.sort()
        
        tmp = [int(x.split('_')[-1]) for x in tmp]

        return tmp[:k]