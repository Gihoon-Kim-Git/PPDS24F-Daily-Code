class Solution:
    def isPalindrome(self, s: str) -> bool:
        s=s.lower()
        ans = ""
        alpha = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9']

        for alphabet in s:
            if alphabet in alpha:
                ans += alphabet
        
        print(ans)
        return  ans == ans[::-1]