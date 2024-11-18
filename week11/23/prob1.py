# 125. Valid Palindrome

def solution(words):
    new_words = words.replace(" ", "").lower()
    res = ""
    for chr in new_words:
        if chr.isalpha() or chr.isnumeric():
            res += chr
    return res == res[::-1]

# Driver Code
if __name__=="__main__":
    # input
    s = "A man, a plan, a canal: Panama"
    print(solution(s))