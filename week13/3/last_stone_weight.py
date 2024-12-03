# You are given an array of integers `stones` where stones[i] is the weight of the ith stone.
#
# We are playing a game with the stones. On each turn, we choose the heaviest two stones
# and smash them together. Suppose the heaviest two stones have weights x and y with x <= y.
# The result of this smash is:
#
# - If x == y, both stones are destroyed.
# - If x != y, the stone of weight x is destroyed, and the stone of weight y has a new weight y - x.
#
# At the end of the game, there is at most one stone left.
#
# Return the weight of the last remaining stone. If there are no stones left, return 0.
#
# Example 1:
# Input: stones = [2,7,4,1,8,1]
# Output: 1
# Explanation:
# Combine 7 and 8 to get 1, array becomes [2,4,1,1,1]
# Combine 2 and 4 to get 2, array becomes [2,1,1,1]
# Combine 2 and 1 to get 1, array becomes [1,1,1]
# Combine 1 and 1 to get 0, array becomes [1]
# Return the last remaining stone: 1
#
# Example 2:
# Input: stones = [1]
# Output: 1
#
# Constraints:
# - 1 <= stones.length <= 30
# - 1 <= stones[i] <= 1000


def lastStoneWeight(stones):

    def custom_sort(arr):
        # Implement selection sort in descending order
        n = len(arr)
        for i in range(n):
            # Find the maximum element in the remaining unsorted part
            max_idx = i
            for j in range(i + 1, n):
                if arr[j] > arr[max_idx]:
                    max_idx = j
            # Swap the maximum element with the current element
            arr[i], arr[max_idx] = arr[max_idx], arr[i]

    while len(stones) > 1:

        custom_sort(stones)
        max_first, max_second = stones[0], stones[1]
        # Replacing is not necessary
        # just can remove the stones by sorted order every time

        stones = stones[2:] # first two removed
        if max_first != max_second:
            # stone of weight x is destroyed, and stone of weight y has new weight y-x
            stones.append(max_first - max_second)
        # if x == y, both stones are destroyed

    # at most one stone left
    if stones:
        return stones[0] # weight of the last remaining stone
    else:
        return 0
    

# Example Testcase
stones1 = [2,7,4,1,8,1]
stones2 = [1]
print(lastStoneWeight(stones1)) # 1
print(lastStoneWeight(stones2)) # 1