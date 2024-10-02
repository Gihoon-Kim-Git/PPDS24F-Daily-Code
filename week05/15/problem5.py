def onetwothree(n):
    if n == 1:
        return 1
    elif n == 2:
        return 2
    elif n == 3:
        return 4
    else:
        return onetwothree(n-1) + onetwothree(n-2) + onetwothree(n-3)

T = int(input())
n = []
for i in range(T):
    n.append(int(input()))
    
for i in range(T):
    print(onetwothree(n[i]))
        
