def add123(n):
    if n == 1:
        return 1
    elif n == 2:
        return 2
    elif n == 3:
        return 4
    else:
        return add123(n-1) + add123(n-2) + add123(n-3)

T = int(input()) # Number of test cases
n = []
for i in range(T):
    n.append(int(input())) # Read all test cases
    
for i in range(T):
    print(add123(n[i])) # Print result for each test case