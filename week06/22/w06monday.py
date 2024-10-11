def solution(S):
    stack = []
    brackets = {')': '(', ']': '[', '}': '{'}
    
    for char in S:
        if char in "({[":
            stack.append(char)
        elif char in ")}]":
            if stack and stack[-1] == brackets[char]:
                stack.pop()
            else:
                return 0
    if stack:
        return 0
    else:
        return 1