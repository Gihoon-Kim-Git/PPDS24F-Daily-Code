def solution(S):
    s = []
    dic = {"}":"{", ")":"(", "]":"["}
    for i in S:
        if i in dic.values():   # 여는 것
            s.append(i)
        elif i in dic.keys():   # 닫는 것
            if len(s) == 0 or dic[i] != s[-1]:     # 닫는 게 더 많거나 짝이 안 맞으면
                return 0
            s.pop()
    if len(s) > 0:    # 여는 게 더 많으면
        return 0
    return 1


print(solution("{[()()]}"))    # 1
print(solution("([)()]"))      # 0
print(solution(""))            # 1
print(solution("(U)"))         # 1
print(solution(")("))          # 0
print(solution("(((("))        # 0
print(solution("))))"))        # 0