# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(S):
    # Implement your solution here
    stack = []
    for i in range(len(S)):
        currentChar = S[i]

        if len(stack) == 0:
            stack.append(currentChar)

        elif (currentChar == ')' and stack[-1] == '('):
            stack.pop(-1)
        elif (currentChar == '}' and stack[-1] == '{'):
            stack.pop(-1)
        elif (currentChar == ']' and stack[-1] == '['):
            stack.pop(-1)
        else:
            stack.append(currentChar)

    if (len(stack) == 0):
        return 1
    else:
        return 0