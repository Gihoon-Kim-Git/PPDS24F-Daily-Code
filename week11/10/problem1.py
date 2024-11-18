class Solution:
    def isPalindrome(self, s: str) -> bool:

        filtered_chars = [char.lower() for char in s if char.isalnum()]
        normalized_string = ''.join(filtered_chars)
        
        return normalized_string == normalized_string[::-1]
    