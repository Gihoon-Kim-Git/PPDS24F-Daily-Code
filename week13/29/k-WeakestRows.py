"""
<The K Weakest Rows in a Matrix>

You are given an m x n binary matrix 'mat' of 1's (representing soldiers) and 0's (representing civilians). 
The soldiers are positioned in front of the civilians. 
That is, all the 1's will appear to the left of all the 0's in each row.

A row i is weaker than a row j if one of the following is true:

- The number of soldiers in row i is less than the number of soldiers in row j.
- Both rows have the same number of soldiers and i < j.

Return the indices of the top-k weakest rows in the matrix ordered from weakest to strongest.
"""

def kWeakestRows(mat, k):
    """
    1. Count soldiers: 여기서 binary search 사용 <- 1이 항상 왼쪽에 있다는 특성 덕
    2. Sort Rows: 약한 순서대로 sorting. 값이 같으면 index 사용
    3. Sorting한 거에서 top-k select
    """

    def count_soldiers(row):
        left, right = 0, len(row)
        while left < right:
            mid = (left + right) // 2
            if row[mid] == 1:
                left = mid + 1
            else:
                right = mid
        return left       # 가장 왼쪽의 0(1에서 0으로 되는 지점)의 index
    
    strength = [(count_soldiers(row),i) for i, row in enumerate(mat)]   # index 정보도 같이 저장

    strength.sort()

    return [strength[i][1] for i in range(k)]

print(kWeakestRows([[1,1,0,0,0],
                    [1,1,1,1,0],
                    [1,0,0,0,0],
                    [1,1,0,0,0],
                    [1,1,1,1,1]], 3))   # [2,0,3]
print(kWeakestRows([[1,0,0,0],
                    [1,1,1,1],
                    [1,0,0,0],
                    [1,0,0,0]], 2))     # [0,2]