"""
<Stone Game IX>

Alice and Bob continue their games with stones. There is a row of n stones, and each stone has an associated value. You are given an integer array stones, where stones[i] is the value of the ith stone.

Alice and Bob take turns, with Alice starting first. On each turn, the player may remove any stone from stones. The player who removes a stone loses if the sum of the values of all removed stones is divisible by 3. Bob will win automatically if there are no remaining stones (even if it is Alice's turn).

Assuming both players play optimally, return true if Alice wins and false if Bob wins.

"""




def stoneGameIX(stones):
    count0 = sum(1 for x in stones if x % 3 == 0)
    count1 = sum(1 for x in stones if x % 3 == 1)
    count2 = sum(1 for x in stones if x % 3 == 2)

    if min(count1, count2) == 0:
        return count0 % 2 == 1 
    
    return (count0 % 2 == 0) 



print(stoneGameIX([2,1]))  # true
print(stoneGameIX([2]))  # false
print(stoneGameIX([5,1,2,4,3]))  # false

