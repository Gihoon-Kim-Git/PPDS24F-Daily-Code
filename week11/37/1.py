class Solution:
    def isPalindrome(self, s: str) -> bool:
        new_s = ''.join(char.lower() for char in s if char.isalnum())
        reverse_s = ''.join(reversed(new_s))
        
        return new_s == reverse_s