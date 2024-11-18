# 14. Longest Common Prefix
class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        pref = strs[0]
        pref_len = len(pref)
        for s in strs[1:]:
            while pref != s[0:pref_len]:
                pref_len -= 1
                if pref_len == 0:
                    return ""
                pref = pref[0:pref_len]
        return pref

strs = ['flower', 'flow', 'flight']
sol = Solution()
print(sol.longestCommonPrefix(strs))