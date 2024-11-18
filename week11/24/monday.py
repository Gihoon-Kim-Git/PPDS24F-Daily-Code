# Valid Palindrome

class Solution:
    def isPalindrome(self, s: str) -> bool:

        # Convert string to lowercase and remove non-alphanumeric characters
        s = ''.join(char.lower() for char in s if char.isalnum())
        
        # # Convert string to list
        # char_list = list(filtered_str)
        
        # # Check if palindrome
        # left, right = 0, len(char_list) - 1
        # while left < right:
        #     if char_list[left] != char_list[right]:
        #         return False
        #     left += 1
        #     right -= 1
        # return True
        
        # check if reverse string is the same as the original string
        return s == s[::-1]
    
if __name__ == "__main__":
    sol = Solution()
    print(sol.isPalindrome("A man, a plan, a canal: Panama"))
    print(sol.isPalindrome("race a car"))
    print(sol.isPalindrome(" "))