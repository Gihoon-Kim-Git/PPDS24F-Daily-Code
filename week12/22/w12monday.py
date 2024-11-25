import heapq

class Solution(object):
    def frequencySort(self, s):
        freq = {}
        for char in s:
            freq[char] = freq.get(char, 0) + 1
        
        max_heap = [(-count, char) for char, count in freq.items()]
        heapq.heapify(max_heap)
        
        result = []
        while max_heap:
            count, char = heapq.heappop(max_heap)
            result.append(char * -count)
        
        return ''.join(result)
