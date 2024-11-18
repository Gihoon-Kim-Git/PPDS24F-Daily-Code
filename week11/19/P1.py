class Solution(object):
    def isPalindrome(self, s):
        c = ""
        for ch in s:
            if ch.isalnum():
                c += ch.lower()

        def lpsHelp(s, start, end):
            if (end - start < 0):
                return False
            if (s[start] != s[end]):
                return False
            if (0 <= end - start <= 1):
                return True
            return lpsHelp(s, start+1, end-1)
        
        if (c == ""):
            return True
        return lpsHelp(c, 0, len(c)-1)

if __name__ == "__main__":
    result = Solution()
    print(result.isPalindrome("A man, a plan, a canal: Panama"))
    print(result.isPalindrome("race a car"))
    print(result.isPalindrome(" "))