# Longest Common Prefix
from typing import List

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""
        
        prefix = strs[0]
        for s in strs[1:]:
            while not s.startswith(prefix):
                prefix = prefix[:-1] # Remove the last character of the prefix
            if prefix == "":
                return ""
        return prefix
    
if __name__ == "__main__":
    sol = Solution()
    print(sol.longestCommonPrefix(["flower","flow","flight"]))
    print(sol.longestCommonPrefix(["dog","racecar","car"]))