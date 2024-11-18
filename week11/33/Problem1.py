# 주어진 string에서 non-alphanumeric character를 제거한 string이 palindrome인지

"""
sList = [c.lower() for c in s if c.isalnum()] << 다른 풀이 참고한 것
"""
class Solution:
    def isPalindrome(self, s: str) -> bool:
        sList = [c.lower() for c in s if c.isalnum()]
        i, j = 0, len(sList)-1
        while i <= j:
            if sList[i] != sList[j]:
                return False
            i += 1
            j -= 1
        return True