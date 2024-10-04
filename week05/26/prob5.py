def count_ways(n):
    if n == 0:
        return 1
    elif n < 0:
        return 0
    
    return count_ways(n-1) + count_ways(n-2) + count_ways(n-3)

T = int(input().strip())

for _ in range(T):
    n = int(input().strip())
    print(count_ways(n))