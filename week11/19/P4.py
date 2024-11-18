class Solution(object):
    def longestCommonPrefix(self, strs):
        if not strs:
            return ""
        answer = strs[0]
        for s in range(1, len(strs)):
            answer = self.lcpHelp(answer, strs[s])
        return answer
    
    def lcpHelp(self, s1, s2):
        minlen = min(len(s1), len(s2))
        for i in range(minlen):
            if (s1[i] != s2[i]):
                return s1[:i]
        return s1[:minlen]
        
if __name__ == "__main__":
    result = Solution()
    strs = ["flower","flow","flight"]
    print(result.longestCommonPrefix(strs))
    strs = ["dog","racecar","car"]
    print(result.longestCommonPrefix(strs))
    strs = ["cir","car"]
    print(result.longestCommonPrefix(strs))