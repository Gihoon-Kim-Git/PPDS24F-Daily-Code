# leetcode 2029

def stoneGameIX(stones):
    count = [0, 0, 0]
    for stone in stones:
        count[stone % 3] += 1

    # Case where only 0s are present
    if count[1] == 0 and count[2] == 0:
        return False
    
    # If either 1s or 2s are absent, Alice cannot avoid a loss.
    if count[1] == 0 or count[2] == 0:
        return (count[0] % 2 == 1)

    # Otherwise, check based on parity of counts
    return abs(count[1] - count[2]) > 2 or (count[0] % 2 == 0)
