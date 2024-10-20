"""
Problem: Pascal's Triangle - Row Generation

Given an integer rowIndex, return the rowIndex-th (0-indexed) row of Pascal's triangle.
In Pascal's triangle:
    - Each row starts and ends with 1.
    - Each internal element is the sum of the two elements directly above it.

For example:
    Input: rowIndex = 3
    Output: [1, 3, 3, 1]

Key Constraints:
    - 0 <= rowIndex <= 33

Solution Explanation:
    1. We initialize the row with all elements set to 1 since every row in Pascal's triangle 
       starts and ends with 1.
    2. We build the row iteratively, using the current state of the same list to calculate
       the new values.
    3. **Why Reverse Updating?**
        - If we update the row from left to right, we may overwrite values that are still 
          needed for future computations.
        - By updating the row **from right to left**, we ensure that each element uses the 
          original values from the previous iteration without unintended overwrites.
    4. This solution works in O(n^2) time complexity and O(n) space complexity, where n is 
       the rowIndex, because we only store a single row at any time.

Example Usage:
    Input: rowIndex = 3
    Output: [1, 3, 3, 1]

"""

def getRow(rowIndex):
    # row[i][0] = row[i][-1] = 1
    ans = [1] * (rowIndex+1)
    # first two rows
    if rowIndex < 2:
        return ans

    # row[i-1][j-1] + row[i-1][j] = row[i][j] (j = 1,2,..,i-1)
    for i in range(2, rowIndex+1):
        # # [1, 2, 1] -> [1, 3, 4, 1]: incorrect result
        # for j in range(1, i):
        #     ans[j] += ans[j-1]

        # REVERSE ORDER UPDATE
        # 한칸 전의 값을 사용하기 때문에, 중복 계산 피하기 위해 뒤에서부터 계산
        for j in range(i-1, 0, -1):
            ans[j] += ans[j-1]
    
    return ans