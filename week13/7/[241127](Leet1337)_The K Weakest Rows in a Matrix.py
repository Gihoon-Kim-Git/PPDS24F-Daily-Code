"""You are given an m x n binary matrix mat of 1's (representing soldiers) and 0's (representing civilians). The soldiers are positioned in front of the civilians. That is, all the 1's will appear to the left of all the 0's in each row.

A row i is weaker than a row j if one of the following is true:

The number of soldiers in row i is less than the number of soldiers in row j.
Both rows have the same number of soldiers and i < j.
Return the indices of the k weakest rows in the matrix ordered from weakest to strongest."""

"""Constraints:
    m == mat.length
    n == mat[i].length
    2 <= n, m <= 100
    1 <= k <= m
    matrix[i][j] is either 0 or 1."""
    
"""수도코드
목표 : mat의 각 row에 대해, (row 안의1 개수, index)를 heapq에 넣고, 작은 거부터 차례로 K개를 빼내면서 list에 해당 index를 저장한 후, 그 list를 반환. 

1. rows = [] : row별 (1 개수, index)를 담을 heapq

2. mat[i]를 순회한다. (i는 0 ~ N-1)
    rows에 (sum(mat[i], i))를 넣는다.(heappush)

3. answer = [] 초기화 : K개의 weakest row index를 담을 list

4. K번동안 
    rows에서 heappop을 하고
    heappop한 요소에서 index값을 answer에 추가한다.

4. answer를 반환한다.
"""

#%%
import heapq

class Solution(object):
    def kWeakestRows(self, mat, k):
        """
        :type mat: List[List[int]]
        :type k: int
        :rtype: List[int]
        """
        
        rows = []
        
        for i in range(len(mat)):
            heapq.heappush(rows, (sum(mat[i]), i))
        
        answer = []
        
        for _ in range(k):
            cur = heapq.heappop(rows)
            answer.append(cur[1])
        
        return answer
    

mat = [[1,1,0,0,0],
        [1,1,1,1,0],
        [1,0,0,0,0],
        [1,1,0,0,0],
        [1,1,1,1,1]]
k = 3
sol1 = Solution()
print(sol1.kWeakestRows(mat, k))
# %%
