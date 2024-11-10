def solution(S):
    # Dictionary to match the opening and closing brackets
    matching_bracket = {')': '(', ']': '[', '}': '{'}
    
    # Stack to keep track of opening brackets
    stack = []
    
    for char in S:
        # If it's an opening bracket, push it onto the stack
        if char in "({[":
            stack.append(char)
        # If it's a closing bracket
        elif char in ")}]":
            # Check if the stack is not empty and the top of the stack matches the current closing bracket
            if not stack or stack[-1] != matching_bracket[char]:
                return 0
            # If they match, pop the top of the stack
            stack.pop()
    
    # If the stack is empty, the string is properly nested, otherwise it's not
    return 1 if not stack else 0