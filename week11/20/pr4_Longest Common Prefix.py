class Solution:
    def longestCommonPrefix(self, strs: list[str]) -> str:
        ans = ""
        if ans in strs: return ans
        
        temp = strs[0]
        while temp:
            ch = temp[0]
            for i in range(1,len(strs)):
                if not strs[i].startswith(ch):
                    return ans
                else : strs[i] = strs[i][1:]
            ans += ch
            temp = temp[1:]
        return ans