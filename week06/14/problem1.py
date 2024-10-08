## Monday. [Brackets](https://app.codility.com/programmers/lessons/7-stacks_and_queues/brackets/)

def solution(S):
    brackets = {"(":")", "{":"}","[":"]"}
    stack = []
    for char in S:
        if brackets.get(char, False): # 여는 괄호이면
            stack.append(char)
        else: # 닫는 괄호이면
            if not stack or brackets[stack.pop()] != char: return 0 # stack 마지막의 괄호와 매칭이 안되면
    if stack: return 0 # stack에 남은 요소가 있으면    
    else: return 1 # stack이 비어있으면