from typing import List

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 1:
            return strs[0]
        commonprefix = ""
        minlen = len(strs[0])        
        for i in range(1, len(strs)):
            minlen = min(minlen, len(strs[i]))      

        for j in range(minlen):
            letter = strs[0][j]
            for i in range(1, len(strs)):                                 
                if strs[i][j] != letter:
                    return commonprefix
            commonprefix = commonprefix+letter    
        return commonprefix
        