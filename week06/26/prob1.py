def solution(S):
    bracket = {"{": "}", "(": ")", "[": "]"}
    stack = []
    for s in S:
        if s in bracket:
            stack.append(s)
        else:
            if not stack or bracket[stack.pop()] != s:
                return 0
    if stack:
        return 0
    return 1