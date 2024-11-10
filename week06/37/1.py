def solution(S):
    S_stack = []
    matches = {')': '(', '}': '{', ']': '['}
    
    for char in S:
        if char in "({[":
            S_stack.append(char)
        elif char in ")}]":

            if not S_stack or S_stack[-1] != matches[char]:
                return 0
            S_stack.pop()
    
    return 1 if not S_stack else 0