# week 13

# Monday. [Last Stone Weight](https://leetcode.com/problems/last-stone-weight/description/)

class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        # Creating a maxheap using minheap mthod for an array
        stones = [-s for s in stones]

        heapq.heapify(stones)

        while len(stones) > 1:
            first = abs(heapq.heappop(stones))
            second = abs(heapq.heappop(stones))
            if first > second:
                heapq.heappush(stones, -1*(first-second))
        
        # Edge case
        if not stones:
            return 0

        return abs(stones[0])