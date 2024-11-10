from collections import Counter

class Solution:
    def stoneGameIX(self, stones: List[int]) -> bool:
        counts = Counter(stone % 3 for stone in stones)
        remainder_0, remainder_1, remainder_2 = counts[0], counts[1], counts[2]

        if remainder_0 % 2 == 0:
            return remainder_1 >= 1 and remainder_2 >= 1
        else:
            return abs(remainder_1 - remainder_2) > 2