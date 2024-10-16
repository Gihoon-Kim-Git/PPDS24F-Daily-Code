"""문제
row Index를 받았을 때, 해당 row의 pascal triangle값을 list로 return.
"""

"""풀이1 : 재귀적 방식
    1.(Base) rowIndex가 A일때, list[0], list[A]는 1이고.
    2. (Recursive)나머지는 Row[n][i] = Row[n-1][i-1] + Row[n-1][i]
"""
"""풀이2 : Iterative 방식
    1. Row[n][i] = Row[n-1][i-1] + Row[n-1][i] 식을 사용하는데... Row[n]를 temp로, Row[n-1]을 prev로.
    2. prev = [] 에서 시작해서, prev를 사용해서 temp를 만들고, temp를 prev로 바꿔주는 과정을 반복하다가, 원하는 시점의 temp가 나왔을 때 return
"""

"""풀이3 : Dynamic Programming
    1. 삼각형형태로 DP table을 만든다고 생각하면 됨.
    2. (rowIndex + 1)개의 row를 파스칼 삼각형. 이 삼각형을 DPtable이라 보면 되겠음. t = [1] * (rowIndex+1)
    3. 하나의 row를 채워가는 for loop
        for i in range(rowIndex+1) :
            t[i] = [1]*(i+1)
            for j in range(1, i):
                t[i][j] = t[i-1][j-1] + t[i-1][j]
    return t[rowIndex]
"""

# 0 [1]
# 1 [1, 1]
# 2 [1,2,1] i1 = j0+j1
# 3 [1,3,3,1] i1 = j0+j1, i2 = j1+j2
# 4 [1,4,6,4,1] i3 = j2+j3
# 5 [1,5,10,10,5,1]

# 풀이1 : 재귀
def getRow(rowIndex)->list:
    #Base case
    if rowIndex == 0 :
        row = [1]
        return row
    elif rowIndex == 1:
        row = [1,1]
        return row
    
    #Recursive
    row = [1] * (rowIndex+1) # rowIndex+1 길이만큼.
    row_pre = getRow(rowIndex-1)
    for i in range(1, rowIndex):
        row[i] = row_pre[i-1] + row_pre[i]
    return row
    

#풀이2 : Iterative
def getRow(rowIndex) :
    prev = []
    for i in range(rowIndex+1):
        temp = [1]* (i+1)
        for j in range(1,i):
            temp[j] = prev[j] + prev[j-1]
        prev = temp
    
    return temp

#풀이3 : DP
def getRow(rowIndex):
    dpT = [1] * (rowIndex+1)
    for i in range(rowIndex+1):
        dpT[i]  = [1]*(i+1) #i번째 row를 채우는 과정
        for j in range(1, i):
            dpT[i][j] = dpT[i-1][j-1] + dpT[i-1][j]
    return dpT[rowIndex]



#test
for i in range(6):
    print(f"{i} Index의 getRow 결과는 {getRow(i)}")
