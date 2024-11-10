def solution(S):
    brackets = {"(":")", "{":"}", "[":"]"} 
    stack = []
    for char in S:
        if brackets.get(char, False):
            stack.append(char)
        else:
            if not stack or brackets[stack.pop()] != char: return 0
    if stack:
        return 0
    else:
        return 1

# Driver Code
if __name__=="__main__":
    s1 = "{[()()]}"
    s2 =  "([)()]"
    print(solution(s1))
    print(solution(s2))