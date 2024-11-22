# string이 주어졌을때 알파벳의 빈도 순으로 return

"""
value를 기준으로 sort -> key= lambda item:item[1]
"""
class Solution:
    def frequencySort(self, s: str) -> str:
        alpDict = {}
        ans = ""
        for alp in s:
            if alp in alpDict:
                alpDict[alp] += 1
            else:
                alpDict[alp] = 1
        
        alpDict = sorted(alpDict.items(), key= lambda item:item[1], reverse=True)
        for key, value in alpDict:
            ans += key * value
        
        return ans


"""
GPT 풀이
: Counter
"""
from collections import Counter
class Solution:
    def frequencySort(self, s: str) -> str:
        # Count the frequency of each character
        freq = Counter(s)
        
        # Sort the characters by frequency in decreasing order, and by their natural order if frequencies match
        sorted_chars = sorted(freq.keys(), key=lambda x: -freq[x])
        
        # Build the result string
        result = ''.join(char * freq[char] for char in sorted_chars)
        
        return result