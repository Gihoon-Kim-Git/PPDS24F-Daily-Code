import heapq

class Solution(object):
    def largestNumber(self, nums):
        nums = list(map(str, nums))
        heap = []
        for num in nums:
            heapq.heappush(heap, (-1 * int(num * 10), num))
        result = []
        while heap:
            result.append(heapq.heappop(heap)[1])
        return str(int(''.join(result)))