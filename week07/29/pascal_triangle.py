# def getRow(rowIndex):
    
#     result = [[1]]

#     for row in range(1,rowIndex+1):    # 행별 순회
#         new_row = []
#         previous_row = result[row-1]
#         new_row.append(1)
#         for i in range(len(previous_row)-1):     # 한 행 내 순회
#             new_row.append(previous_row[i]+previous_row[i+1])
#         new_row.append(1)
#         result.append(new_row)

#     return result[rowIndex]


# rowIndex = 3
# print(getRow(rowIndex))


# 최적화 버전: triangle[n][k]=triangle[n−1][k−1]+triangle[n−1][k]
def getRow(rowIndex):
    
    result = [[] for _ in range(rowIndex+1)]

    for row in range(0, rowIndex+1):
        if row == 0: 
            result[row].append(1)
            continue

        for i in range(0, row+1):     # 각 행에 있어야 할 수 = 행 index + 1
            if i == 0 or i == row:
                result[row].append(1)
            else:
                result[row].append(result[row-1][i-1] + result[row-1][i])

    return result[rowIndex]


rowIndex = 3
print(getRow(rowIndex))  # [1,3,3,1]