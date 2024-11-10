lst = [0,0,0,0,0,0,0,0,0,0,0,0,0]
lst[0]=1
lst[1]=1
lst[2]=2
lst[3]=4

for i in range(4,11):
    lst[i] = lst[i-1] + lst[i-2] +lst [i-3] 


n = int(input())
temp = []
for i in range(n):
    temp.append(int(input()))

ans = []
for i in range(n):
    ans.append(lst[temp[i]])

for i in range(n):
    print(ans[i])
