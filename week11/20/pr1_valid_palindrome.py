class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()
        temp = ""
        for i in range(len(s)):
            if s[i].isalpha() or s[i].isnumeric():
                temp += s[i]
        # if not temp : return True
        # check palidrome
        h = 0
        t = len(temp)-1
        while h <= t :
            if temp[h] != temp[t] : return False
            h+=1
            t-=1
        return True

# test1 = 3
# test2 = 5
# print(test1 if test1>test2 else test2)
# print(test2>test1 ? test1 : tset2)

# temp = "abcd"
# print(temp[::-1])
# print(temp[1:])
# print(temp[:1])
# print(temp[::])