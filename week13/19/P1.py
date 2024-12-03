import heapq

class Solution(object):
    def lastStoneWeight(self, stones):
        maxHeap = []
        for i in stones:
            heapq.heappush(maxHeap, -i)
        while (len(maxHeap) > 1):
            first = heapq.heappop(maxHeap)
            second = heapq.heappop(maxHeap)
            if (first < second):
                heapq.heappush(maxHeap, first - second)
        if (len(maxHeap) > 0):
            return -maxHeap[0]
        return 0

if __name__ == "__main__":
    result = Solution()
    stones = [2,7,4,1,8,1]
    print(result.lastStoneWeight(stones))
    stones = [1]
    print(result.lastStoneWeight(stones))