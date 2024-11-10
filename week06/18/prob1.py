# Prob1
def solution(S):
    stack = []
    matching_bracket = {'{':'}', '(':')', '[':']'}
    
    for bracket in S:
        if bracket in matching_bracket.keys():
            stack.append(bracket)
        else:
            if not stack or matching_bracket[stack[-1]] != bracket:
                return 0
            else:
                stack.pop()
                
    return 1

def main():
    ex1 = '[{}()[]]'
    ex2 = '[{]}'
    ex3 = ''
    ex4 = '}()[{}]'
    
    print(solution(ex1))
    print(solution(ex2))
    print(solution(ex3))
    print(solution(ex4))

if __name__ == '__main__':
    main()