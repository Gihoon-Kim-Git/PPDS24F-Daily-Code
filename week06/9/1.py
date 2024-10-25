def solution(S):
    mapping = {'(':0, '[':1, '{':2, '}':3, ']':4, ')':5}
    stack = []

    for s in S:
        if s not in mapping:
            continue
        
        if mapping[s] <= 2:
            stack.append(s)
        
        elif stack:
            p = stack.pop()
            if mapping[s] + mapping[p] != 5:
                return 0
        else :
            return 0
    
    return 1 if not stack else 0


if __name__ == '__main__':
    print(solution("10K )'s + )( + ()"))