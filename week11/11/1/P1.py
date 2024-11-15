#%%
class Solution:
    def isPalindrome(self, s: str) -> bool:
        i = 0
        j = len(s) - 1
        while i < j:
            if s[i].isalnum() and s[j].isalnum():
                if s[i].lower() == s[j].lower():
                    i += 1
                    j -= 1
                else:
                    return False
            elif not s[i].isalnum():
                i += 1
            elif not s[j].isalnum():
                j -= 1
        return True




#%%
#이렇게 해도 되긴 하는데 복잡하고 메모리 exceed남
class Solution:
    def isPalindrome(self, s: str) -> bool:
        if len(s) == 0 or len(s) == 1:
            return True
        i = 0
        j = len(s)-1
        while not s[i].isalnum() and i < len(s)-1:
            i+=1
        while not s[j].isalnum() and j > 0:
            j-=1
        s = s[i:j+1]

        if len(s) == 0 or len(s) == 1:
            return True
        
        if s[0].lower() == s[-1].lower():
            return self.isPalindrome(s[1:-1])
        else:
            return False

#%%
s = Solution()
print(s.isPalindrome("aa"))
# %%
