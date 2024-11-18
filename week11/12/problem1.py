class Solution:
    def isPalindrome(self, s: str) -> bool:
        s_low =[]
        for char in s:
            if char.isalnum() ==True:
                s_low.append(char.lower())

        return(s_low == s_low[::-1])