def count_123(x: int) -> int:
    # base case
    if x == 0:
        return 1
    elif x < 0:
        return 0
    else:
        return count_123(x-1) + count_123(x-2) + count_123(x-3)
    

if __name__ == "__main__":
    for i in range(1, 11):
        print(count_123(i))
