# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(S):
    r = len(S)-1
    for i in range(len(S)):
        if S[i] == "(" or S[i] ==")":
            if S[r-i] == ")" or S[r-i] == "(":
                continue
            else :
                return 0
        elif S[i] == "[" or S[i] == "]" or S[i] == "{" or S[i] == "}":
            if ord(S[r-i]) - ord(S[i]) == 2 or ord(S[r-i]) - ord(S[i]) == -2:
                continue
            else :
                return 0
    return 1
        
