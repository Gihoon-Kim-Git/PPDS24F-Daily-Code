# week 12

# Monday. [Sort Characters By Frequency](https://leetcode.com/problems/sort-characters-by-frequency/description/)

class Solution:
    def frequencySort(self, s: str) -> str:
        return ''.join([k*v for k,v in Counter(s).most_common()])