# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(S):
    # Implement your solution here
    if len(S) == 0:
        return 1    
    if len(S) == 1 or (S[0] in (")", "}", "]")):
        return 0

    bracket = []
    for i in range(len(S)):
        if S[i] in ("[", "{", "("):
            bracket.append(S[i])

        elif S[i] == ")":
            if bracket and bracket[-1] == "(":
                bracket.pop()
            else:
                return 0
        elif S[i] == "}":
            if bracket and bracket[-1] == "{":
                bracket.pop()
            else:
                return 0
        elif S[i] == "]":
            if bracket and bracket[-1] == "[":
                bracket.pop() 
            else:
                return 0
    return 1 if not bracket else 0
