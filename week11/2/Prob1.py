class Solution:
    def isPalindrome(self, s: str) -> bool:
        # text전처리
        s = s.lower()
        s_alnum = "".join(filter(str.isalnum, s))
        """
        def palindrome(s_alnum: str) -> bool:
            len_num = len(s_alnum)
            #print(len_num)
            if len_num <= 1:
                # base case
                return True
            else:
                # regular case
                #print(s_alnum)
                if s_alnum[0] == s_alnum[-1]:
                    #print(s_alnum, True)
                    return palindrome(s_alnum[1:-1])
                else:
                    #print(s_alnum, False)
                    return False
        return palindrome(s_alnum)
        """
        # slice text : half
        len_alnum = len(s_alnum)
        len_slice = len_alnum // 2
        s_left = s_alnum[:len_slice]
        s_right = s_alnum[(len_alnum - len_slice):]
        if s_left == s_right[::-1]:
            return True
        else:
            return False

sol = Solution()

print(sol.isPalindrome("race a car"))
