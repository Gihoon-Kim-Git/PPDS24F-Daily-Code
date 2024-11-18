def isPalindrome(s):
    s = s.lower()
    filtered = ""
    for c in s:
        if c.isnumeric() or c.isalpha():
            filtered += c

    for i in range(len(filtered)//2):
        if filtered[i] != filtered[len(filtered)-1-i]:
            return False
    return True



print(isPalindrome("A man, a plan, a canal: Panama"))  # true
print(isPalindrome("race a car"))  # false
print(isPalindrome(" "))  # true