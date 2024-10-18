# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(S):
    # Implement your solution here

    invalid = 1         # 체크 하다가 이상함을 한 번이라도 발견하면 바로 out
    stack = []

    for c in S:
        # open 을 만나면 enqueue
        if c == '(':
            stack.append(')')
        elif c == '{':
            stack.append('}')
        elif c == '[':
            stack.append(']')

        # close 를 만나면 가능한지 체크 후 dequeue
        else:
            # stack 이 empty : 부적절한 close
            if len(stack) == 0:
                invalid = 0
                break
            # stack.top 이 동류가 아님 : 부적절한 close
            elif stack[-1] != c:
                invalid = 0
                break
            # 그 외 : 적절한 close : dequeue
            else:
                stack.pop()
    
    # for loop 은 close 가 적절했는지를 검사했음.
    # open 이 적절했는지 : stack 이 for loop 종료 후 empty 인지 확인해야함
    if invalid == 1 and len(stack) > 0:
        invalid = 0
    
    return invalid
