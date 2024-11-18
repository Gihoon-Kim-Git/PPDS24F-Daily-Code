class Solution:
    def isPalindrome(self, s: str) -> bool:                
        s = s.lower().strip()
                     
        s_ = str()
        for i in range(len(s)):
            if s[i].isalnum():
                s_ = s_ + s[i]       
        
        for i in range(len(s_)//2):
            if s_[i] != s_[-i-1]:
                return False
        return True