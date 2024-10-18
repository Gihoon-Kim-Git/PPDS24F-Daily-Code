"""
Problem: Search a 2D Matrix (Top-Right Corner Approach)

Given an m x n matrix where:
- Each row is sorted in ascending order from left to right.
- Each column is sorted in ascending order from top to bottom.

Approach:
1. Start from the **top-right corner** of the matrix.
2. At each step:
   - If the current element is equal to the target, return True.
   - If the current element is larger than the target, move **left**.
   - If the current element is smaller than the target, move **down**.
3. Continue until either the target is found or we run out of matrix bounds.

Time Complexity: O(m + n) (in the worst case, we traverse both dimensions)
Space Complexity: O(1) (constant space usage)
"""

def searchMatrix(matrix, target):

    m = len(matrix) # number of rows
    if m == 0:
        return False
    n = len(matrix[0]) # number of columns

    # start search from the TOP-RIGHT corner
    row = 0
    col = n-1

    # within the matrix boundaries
    while row < m and col >= 0:
        curr = matrix[row][col]

        if curr == target:
            return True
        
        elif curr > target:
            col -= 1 # move left
        else: # curr < target
            row += 1 # move down

    # loop exit: target was not found
    return False

# Example Usage
matrix1 = [
  [1, 4, 7, 11, 15],
  [2, 5, 8, 12, 19],
  [3, 6, 9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
target1 = 5
target2 = 20

print(searchMatrix(matrix1, target1))
print(searchMatrix(matrix1, target2))
# $ python search_2d_matrix.py
# True
# False

"""
### **왜 Top-Left는 안 되고, Top-Right는 되는 걸까?**

행과 열이 각각 **오름차순(왼쪽에서 오른쪽, 위에서 아래로)**으로 정렬된 2D 행렬에서, **Top-Left(왼쪽 위)**와 **Top-Right(오른쪽 위)**에서 시작했을 때의 탐색 차이를 이해해 봅시다.

---

### **Top-Right(오른쪽 위) 탐색 알고리즘**

- **오른쪽 위에서 출발**하면, 현재 위치에서 **오른쪽**과 **아래쪽**의 값들의 경향을 잘 활용할 수 있습니다.
- **알고리즘**:
  1. 현재 위치의 값이 **타겟보다 크면**, 왼쪽으로 이동합니다.  
     (왜냐하면, 오른쪽에 있는 값들은 모두 현재 값보다 크기 때문에 타겟이 있을 수 없기 때문입니다.)
  2. 현재 위치의 값이 **타겟보다 작으면**, 아래로 이동합니다.  
     (왜냐하면, 위쪽에 있는 값들은 모두 더 작기 때문에 타겟이 있을 가능성이 아래에 있기 때문입니다.)

이런 방식으로 탐색을 계속하면, **무조건 타겟이 있을 수 있는 방향으로만 이동**합니다. 따라서 오른쪽 위에서 시작하면 **불필요한 탐색을 하지 않고 효율적으로 진행**할 수 있습니다.

---

### **Top-Left(왼쪽 위)에서 시작하면 왜 안 될까?**

- **왼쪽 위에서 출발**하면, 문제는 현재 값이 타겟보다 크거나 작은 경우에 **탐색 방향을 제대로 정하지 못한다는 것**입니다.
  1. **현재 값이 타겟보다 크다면**:  
     → 오른쪽으로 가야 할지, 아래로 가야 할지 알 수 없습니다.  
     (두 방향 모두 가능성이 남기 때문에 탐색 효율이 떨어집니다.)
  2. **현재 값이 타겟보다 작다면**:  
     → 마찬가지로 오른쪽이나 아래쪽 둘 다 탐색해야 할 가능성이 남아 있어, **경로를 완전히 배제하지 못합니다**.

결국, **왼쪽 위에서 시작하면 탐색 경로가 많아져 비효율적**이고, 타겟을 놓칠 가능성도 있습니다.

---

### **왜 Top-Right가 더 나은 선택일까?**

1. **오른쪽 위**에서는:
   - 왼쪽으로 갈수록 값이 작아지고, 아래로 갈수록 값이 커집니다.
   - 따라서 **오른쪽 위에서는 "작은 값과 큰 값"을 정확하게 구분**할 수 있습니다.
     - **타겟보다 크면 왼쪽**, **타겟보다 작으면 아래쪽**으로 이동.
     - 이렇게 하면 탐색 경로를 확실히 좁힐 수 있습니다.

2. **왼쪽 위**에서는:
   - 오른쪽과 아래 모두 큰 값이 나올 수 있기 때문에 탐색 방향을 명확하게 정하기 어렵습니다.
   - 그래서 탐색이 효율적이지 않게 됩니다.

---

### **한줄 요약**

- **Top-Right(오른쪽 위)**에서는 탐색 방향을 명확하게 정할 수 있어서 효율적입니다.  
  → **타겟보다 크면 왼쪽, 타겟보다 작으면 아래**로 이동합니다.  
- 반면, **Top-Left(왼쪽 위)**에서는 오른쪽과 아래 모두 가능성이 남아 탐색이 비효율적입니다.
"""