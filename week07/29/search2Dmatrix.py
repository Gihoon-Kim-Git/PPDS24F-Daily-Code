def binarySearch(arr, low, high, target):

    while low <= high:
        mid = (low+high) // 2
        if arr[mid] < target:
            low = mid + 1
        elif arr[mid] == target:
            return mid
        else:
            high = mid - 1

    return -1      # target이 0인 경우 high가 -1까지 내려갈 수 있음.

def searchMatrix(matrix, target):

    if len(matrix) == 0:
            return False
    if len(matrix) == 1:    # 행 벡터
        if target in matrix[0]:
            return True
        return False

    for row in matrix:
        if len(row) == 1:   # 열 벡터
            if target in row:
                return True
            continue
        
        idx = binarySearch(row, 0, len(row)-1, target)
        if idx != -1:
            return True
    return False   



matrix = [[2,5],[2,8],[7,9],[7,11],[9,11]]
target = 7
print(searchMatrix(matrix, target))

