# week 12

# Monday. [Sort Characters By Frequency](https://leetcode.com/problems/sort-characters-by-frequency/description/)
# Tuesday. [Largest Number](https://leetcode.com/problems/largest-number/description/)
# Wednesday. [Battleships in a Board](https://leetcode.com/problems/battleships-in-a-board/description/)
# Thursday. [Implement Queue using Stacks](https://leetcode.com/problems/implement-queue-using-stacks/description/)
# Friday. [Implement Stack using Queues](https://leetcode.com/problems/implement-stack-using-queues/description/)

import heapq

class Solution:
    def frequencySort(self, s: str) -> str:
        freq = {}
        for char in s:
            freq[char] = freq.get(char, 0) + 1
        return ''.join(sorted(s, key=lambda x: (-freq[x], x)))
    
