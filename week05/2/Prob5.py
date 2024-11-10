def sum123(num:int):
    if num == 1:
        return 1
    elif num == 2:
        return 2
    elif num == 3:
        return 4
    else:
        return sum123(num-1) + sum123(num-2) + sum123(num-3)
    

T = int(input())

for i in range(T):
    num = int(input())
    print(sum123(num))
