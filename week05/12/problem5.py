n = int(input())
def recur(i:int)->int:
    if i ==0:
        return 1
    if i ==1:
        return 1
    if i==2:
        return 2
    if i==3:
        return 4
    return recur(i-1)+ recur(i-2)+recur(i-3)

for i in range(n):
    ans=recur(int(input()))
    print(ans)
