def solution(S):
    stack = []
    i = 0
    while True:
        if (i >= len(S)):
            break
        elif (S[i] == '{'):
            stack.append('}')
        elif (S[i] == '['):
            stack.append(']')
        elif (S[i] == '('):
            stack.append(')')
        else:
            if (not stack or S[i] != stack.pop()):
                return 0
        i += 1
    if stack:
        return 0
    return 1

if __name__ == "__main__":
    s1 = "{[()()]}"
    s2 = "([)()]"
    print(solution(s1))
    print(solution(s2))